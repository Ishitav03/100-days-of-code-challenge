//352. Data Stream as Disjoint Intervals
//Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.
//Implement the SummaryRanges class:

// SummaryRanges() Initializes the object with an empty stream.
// void addNum(int value) Adds the integer value to the stream.
// int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.


//Constraints:

// 0 <= value <= 10^4
// At most 3 * 104 calls will be made to addNum and getIntervals.


class SummaryRanges {
public:
    SummaryRanges() {   
    }
    
    void addNum(int val){
    data_given.insert(val);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int start = -1;
        int end = -1;
        for ( auto  &item: data_given) {
            if (start == -1) {
                start = item;
                end = item;
            } else if (item == end + 1) {
                end = item;
            } else {
                res.push_back({start, end});
                start = end = item;
            }
        }
        
        if (start != -1) res.push_back({start, end}); 
        return res;
    }
    private:
    set<int> data_given;
};
