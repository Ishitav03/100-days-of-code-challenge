// 2348. Number of Zero-Filled Subarrays
// Given an integer array nums, return the number of subarrays filled with 0.

// A subarray is a contiguous non-empty sequence of elements within an array.
  
//   Constraints:

// 1 <= nums.length <= 10^5
// -109 <= nums[i] <= 10^9

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        typedef long long ll;
        ll count =0,
        res=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0 ) count++;
            else if(count != 0){
                res += count*(count+1)/2;
                count=0;
            }
        } 
        if(count>0){
            res += count*(count+1)/2;
        }
        return res;
    }
};
