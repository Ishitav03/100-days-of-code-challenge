//567. Permutation in String
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.

//Constraints:

// 1 <= s1.length, s2.length <= 10^4
// s1 and s2 consist of lowercase English letters.


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {0};
        for(char c : s1) map[c-'a']++;
        int j = 0, i = 0, count = s1.size();
        while(j < s2.size()){
            if(map[s2.at(j++)-'a']-- > 0)
                count--;
            if(count == 0) return true;
            if(j-i == s1.size() && map[s2.at(i++) - 'a']++ >= 0)
                count++;
        }
        return false;
    }
};
