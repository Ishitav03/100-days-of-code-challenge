// 704. Binary Search
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.
  
  
//  Constraints:

// 1 <= nums.length <= 10^4
// -104 < nums[i], target < 10^4
// All the integers in nums are unique.
// nums is sorted in ascending order.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int curr=nums[mid];
            if(curr==target) return mid;
            else if(curr>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};
