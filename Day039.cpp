// 45. Jump Game II
// //You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// // 0 <= j <= nums[i] and
// // i + j < n
// // Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Constraints:

// 1 <= nums.length <= 10^4
// 0 <= nums[i] <= 1000


class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i] + i, nums[i-1]);
        }
        int ind = 0, ans = 0;
        while(ind < nums.size() - 1){
        ans++;
        ind = nums[ind];
        }
        return ans;
    }
};
