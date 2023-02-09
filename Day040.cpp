// //2306. Naming a Company
// //You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

// Choose 2 distinct names from ideas, call them ideaA and ideaB.
// Swap the first letters of ideaA and ideaB with each other.
// If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
// Otherwise, it is not a valid name.
// Return the number of distinct valid names for the company.

//Constraints:

// 2 <= ideas.length <= 5 * 10^4
// 1 <= ideas[i].length <= 10
// ideas[i] consists of lowercase English letters.
// All the strings in ideas are unique.


class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> m;
        for(auto i: ideas) m[i]++;

        vector<vector<int>> dp(26, vector<int>(26,0));
        for(int i=0;i<ideas.size();i++){
            string cur=ideas[i];
            char c1=cur[0];
            for(int j=0;j<26;j++){
                char c2=j+'a';
                cur[0]=c2;
                if(m.find(cur)==m.end()){
                    dp[c1-'a'][j]++;
                }
            }
        }

        long res=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                res+=dp[i][j]*dp[j][i];
            }
        }
        return res;
    }
};
