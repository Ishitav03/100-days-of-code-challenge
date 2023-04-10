// 2405. Optimal Partition of String
// Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

// Return the minimum number of substrings in such a partition.

// Note that each character should belong to exactly one substring in a partition.
  
//   Constraints:

// 1 <= s.length <= 10^5
// s consists of only English lowercase letters.
  
  
class Solution {
public:
    int partitionString(string s) {
        int xr=0, res=1;
        for(int i=0;i<s.size();i++){
            if(xr&(1<<(s[i]-'a'))){
                xr=0;
                res++;
            }
            xr^=(1<<(s[i]-'a'));
        }
        return res;
    }
};
