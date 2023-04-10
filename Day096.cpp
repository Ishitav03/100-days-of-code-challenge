// 1254. Number of Closed Islands
// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.
  
// Constraints:

// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1
  
  
 class Solution {
public:
    bool dfs(int i, int j,vector<vector<int>>& grid){
        int n1=grid.size();
        int n2=grid[0].size();
        if(i<0||j<0||i==n1||j==n2) return false;
        if(grid[i][j]==1) return true;
        else{
            grid[i][j]=1;
            bool l=dfs(i,j-1,grid);
            bool r=dfs(i,j+1,grid);
            bool up=dfs(i+1,j,grid);
            bool d=dfs(i-1,j,grid);
            return l&&r&&up&&d;
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0 && dfs(i,j,grid)==true) count++;
            }
        }
        return count;
    }
};
