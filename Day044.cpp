//1523. Count Odd Numbers in an Interval Range
//Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

// Constraints:
// 0 <= low <= high <= 10^9

class Solution {
public:
    int countOdds(int low, int high) {
        int res=0;
        for(int i=low;i<=high;i++){
            if(i%2!=0) res++;
        }
        return res;
    }
};
