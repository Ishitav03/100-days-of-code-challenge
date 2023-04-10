// 2439. Minimize Maximum of Array
// You are given a 0-indexed array nums comprising of n non-negative integers.

// In one operation, you must:

// Choose an integer i such that 1 <= i < n and nums[i] > 0.
// Decrease nums[i] by 1.
// Increase nums[i - 1] by 1.
// Return the minimum possible value of the maximum integer of nums after performing any number of operations.

  
// Constraints:

// n == nums.length
// 2 <= n <= 10^5
// 0 <= nums[i] <= 10^9

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long int ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,(sum+i)/(i+1));
        }
        return ans;
    }
};
