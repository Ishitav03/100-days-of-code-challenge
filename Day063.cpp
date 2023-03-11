// 2444. Count Subarrays With Fixed Bounds
// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.
  
   

// Constraints:

// 2 <= nums.length <= 10^5
// 1 <= nums[i], minK, maxK <= 10^6


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res=0;
        int j=-1, mini=-1, maxi=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK) j=i;
            if(nums[i]==minK) mini=i;
            if(nums[i]==maxK) maxi=i;

            res+=max(0, min(mini, maxi)-j);
        }
        return res;
    }
};
