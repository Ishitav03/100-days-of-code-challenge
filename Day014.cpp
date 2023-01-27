//1061. Lexicographically Smallest Equivalent String
//You are given two strings of the same length s1 and s2 and a string baseStr.
//We say s1[i] and s2[i] are equivalent characters.

// For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
// Equivalent characters follow the usual rules of any equivalence relation:

// Reflexivity: 'a' == 'a'.
// Symmetry: 'a' == 'b' implies 'b' == 'a'.
// Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
// For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

// Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.


//Constraints:

// 1 <= s1.length, s2.length, baseStr <= 1000
// s1.length == s2.length
// s1, s2, and baseStr consist of lowercase English letters.


class Solution {
public:
    int temp[26];    
    int find(int x){
        if(temp[x]==-1) return x;
        return temp[x]=find(temp[x]);
    }
    
    void Union(int x, int y) {
        x = find(x);
        y = find(y);        
        if (x != y) temp[max(x, y)] = min(x, y); 
    }
	
    string smallestEquivalentString(string s1, string s2, string baseStr) {        
        memset(temp, -1, sizeof(temp));        
        for (auto i = 0; i < s1.size(); ++i) 
            Union(s1[i] - 'a', s2[i] - 'a');
        
        for(auto i=0;i<baseStr.size();i++) 
            baseStr[i]=find(baseStr[i]-'a')+'a';

        return baseStr;
    }
};
