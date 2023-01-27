//472. Concatenated Words
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

//A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.


// Constraints:

// 1 <= words.length <= 10^4
// 1 <= words[i].length <= 30
// words[i] consists of only lowercase English letters.
// All the strings of words are unique.
// 1 <= sum(words[i].length) <= 10^5

class Solution {
public:
    bool concat_possible(string &word,vector<string>& words, unordered_map<string,int>&mp){
        int size=word.size();
        for(int i=1;i<size;++i){ 
            string prefix=word.substr(0,i);
            string suffix=word.substr(i);
            if(mp[prefix] && (mp[suffix] || concat_possible(suffix,words,mp))){
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        unordered_map<string,int>mp; 
        for(auto string:words){
            mp[string]++;
        }
        for(auto &word:words){ 
            if(concat_possible(word,words,mp)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};
