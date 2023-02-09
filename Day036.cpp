//438. Find All Anagrams in a String
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


//Constraints:

// 1 <= s.length, p.length <= 3 * 104
// s and p consist of lowercase English letters.


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int c1[26]={0},c2[26]={0},i;
        vector<int>ans;
        int n1 = s.size(),n2=p.size();
        if(n1<n2)return ans;
        for(i=0;i<p.size();i++){
            c1[p[i]-'a']++;
            c2[s[i]-'a']++;
        }
        
        for(i=0;i<26;i++)if(c1[i]!=c2[i]) break;
        if(i==26)ans.push_back(0);
        int j=0,k;
        for(int i=n2;i<n1;i++){
            c2[s[j]-'a']--;
            c2[s[i]-'a']++;
            for(k=0;k<26;k++)if(c1[k]!=c2[k])break;
             
            if(k==26)ans.push_back(j+1);
            j++;
        }
        return ans; 
    }
};
