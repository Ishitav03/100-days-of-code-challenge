// 72. Edit Distance
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character


// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.
  
  
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
    
        int dp[n1+1][n2+1];    
        for (int i = 0; i <= n1; i++) dp[i][0] = i;
        for (int j = 0; j <= n2; j++) dp[0][j] = j;
    
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    int ins = dp[i][j-1]; 
                    int del = dp[i-1][j]; 
                    int rep = dp[i-1][j-1]; 
                    dp[i][j] = 1 + min(ins, min(del,rep));
                }
            }
        }
        return dp[n1][n2];
    }
};
