// 87. Scramble String
// We can scramble a string s to get a string t using the following algorithm:

// If the length of the string is 1, stop.
// If the length of the string is > 1, do the following:
// Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
// Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
// Apply step 1 recursively on each of the two substrings x and y.
// Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
  
  
// Constraints:

// s1.length == s2.length
// 1 <= s1.length <= 30
// s1 and s2 consist of lowercase English letters.
  
  
class Solution {
public:		
		unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
			if(s1==s2) return true;
			int n=s1.size(),
			n2=s2.size();
			if(n==1||n2==1||n!=n2) return false;

			vector a(26, 0), b(26, 0), c(26, 0);
			if (mp.count(s1 + s2)) return mp[s1 + s2];
		
			for (int i = 1; i <= n - 1; i++){
				int j = n - i;
							a[s1[i - 1] - 'a']++;
				b[s2[i - 1] - 'a']++;
				c[s2[j] - 'a']++;
				
				if (a == b && isScramble(s1.substr(0, i), s2.substr(0, i)) && 
				isScramble(s1.substr(i), s2.substr(i)))
				{
					mp[s1 + s2] = true;
					return true;
				}
				if (a == c && isScramble(s1.substr(0, i), s2.substr(j)) && 
				isScramble(s1.substr(i), s2.substr(0, j)))
				{
					mp[s1 + s2] = true;
					return true;
				}
			}
		mp[s1 + s2] = false;
		return false;
	}
};
