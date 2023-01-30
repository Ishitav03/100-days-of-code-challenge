//460. LFU Cache
//Design and implement a data structure for a Least Frequently Used (LFU) cache.

//Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.


//Constraints:

// 0 <= capacity <= 10^4
// 0 <= key <= 10^5
// 0 <= value <= 10^9
// At most 2 * 105 calls will be made to get and put.


class LFUCache {
public:
    int capacity;
    unordered_map<int, pair<int,int>> cache;
    unordered_map<int, list<int>::iterator> listItrMap;
    unordered_map<int,list<int>> freqMap;
    int minFreq=0;
    
    LFUCache(int capacity){
        this->capacity = capacity;
    }
    
    int get(int key){
        if(!cache.count(key))
            return -1;        
        updateFrequency(key);         
        return cache[key].first;
    }
    
    void put(int key, int value){
        if(this->capacity<=0) return;
        // if key is already in cache
        if(cache.count(key)){
            updateFrequency(key);            
            cache[key].first = value;
        }
        else{
            if(cache.size() >= this->capacity){
                // remove last-element in the least-frequent-list
                int leastFrequentKey = freqMap[minFreq].back();
                cache.erase(leastFrequentKey);
                listItrMap.erase(leastFrequentKey);                
                // remove least frequent
                freqMap[minFreq].pop_back();
            } 
            
            // insert value
            cache[key] = {value, 0};
            freqMap[0].push_front(key);
            listItrMap[key] = freqMap[0].begin();
            
            minFreq=0;// reset min frequency
        }
    }
    
    private:
    void updateFrequency(int key){
        int freq = cache[key].second++;
        freqMap[freq].erase(listItrMap[key]);
        freqMap[freq+1].push_front(key);
        listItrMap[key] = freqMap[freq+1].begin();
         if(freqMap[minFreq].size()==0){
              freqMap.erase(minFreq++);
           }
    }
};
