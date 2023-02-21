//35. Search Insert Position
//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

//You must write an algorithm with O(log n) runtime complexity.


//Constraints:

// 1 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// nums contains distinct values sorted in ascending order.
// -10^4 <= target <= 10^4


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for(i=0;i<nums.size();i++)
            if(nums[i]==target || nums[i]>target) break;
        return i;
    }
};
