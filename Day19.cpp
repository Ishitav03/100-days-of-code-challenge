//974. Subarray Sums Divisible by K
//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
//A subarray is a contiguous part of an array.

// Constraints:

// 1 <= nums.length <= 3 * 10^4
// -10^4 <= nums[i] <= 10^4
// 2 <= k <= 10^4


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> sums(k, 0);
        sums[0]++;
        int count= 0;
        int curr= 0;
        for(int i=0;i<nums.size();i++) {
            curr = (curr + nums[i]%k + k)%k;
            count += sums[curr];
            sums[curr]++;
        }
        return count;
    }
};
