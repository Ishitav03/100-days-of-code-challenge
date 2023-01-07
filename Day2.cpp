//290. Word Pattern
//Given a pattern and a string s, find if s follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, int> p;
        map<string, int> w;
        istringstream in(s);
        
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p[pattern[i]] != w[word])
                return false;
            p[pattern[i]] = w[word] = i + 1;
        }
        return i == n;
    }
};
