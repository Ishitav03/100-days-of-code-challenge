// 1020. Number of Enclaves
// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
  
//   Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 0 or 1.


class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1) return;
        grid[i][j]=-1;
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            dfs(i,0,grid);
            dfs(i,grid[0].size()-1,grid);
        }
        for(int j=0;j<grid[0].size();j++){
            dfs(0,j,grid);
            dfs(grid.size()-1,j,grid);
        }

        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};
