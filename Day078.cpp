// 211. Design Add and Search Words Data Structure
// Medium
// 6.7K
// 382
// Companies
// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 
//   Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 3 dots in word for search queries.
// At most 104 calls will be made to addWord and search.
  
  
class WordDictionary {
public:
    vector<string> v;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        int count=0;
        int n=word.size();
        for(int i=0; i<v.size(); i++){
            if(n==v[i].size()){
                for(int j=0; j<n; j++){
                    if(v[i][j]==word[j]||word[j]=='.') count++;
                    else{
                        count=0;
                        break;
                    }
                }
                if(count==n) return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
