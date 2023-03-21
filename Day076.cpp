// 208. Implement Trie (Prefix Tree)
// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


// Constraints:

// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and startsWith.


class Trie {
public:
    unordered_map<string,int>mpp,mp;
    Trie() {
        
    }    
    void insert(string word) {
        mpp[word]++;
        string s;
        for(auto it : word)
        {
            s.push_back(it);
            if(mp[s]==0) mp[s]++;
        }
    }
    
    bool search(string word) {
        if(mpp[word]) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if(mp[prefix]) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
