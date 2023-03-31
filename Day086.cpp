// 64. Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.
  
//   Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 100
  
  
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
         dp[i][1] =grid[i-1][0] + dp[i-1][1];
        }
        for(int j=1;j<=m;j++){
         dp[1][j] = grid[0][j-1] + dp[1][j-1];   
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
