//540. Single Element in a Sorted Array
//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.
  
  
//  Constraints:
// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^5


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            res^=nums[i];
        }
        return res;
    }
};
