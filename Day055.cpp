// 1675. Minimize Deviation in Array
// You are given an array nums of n positive integers.

// You can perform two types of operations on any element of the array any number of times:

// If the element is even, divide it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
// If the element is odd, multiply it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
// The deviation of the array is the maximum difference between any two elements in the array.

// Return the minimum deviation the array can have after performing some number of operations.
  
  
  
//   Constraints:

// n == nums.length
// 2 <= n <= 5 * 10^4
// 1 <= nums[i] <= 10^9


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int m = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                pq.push(nums[i]);
                m = min(m,nums[i]);
            }
            else{
                pq.push(nums[i]*2);
                m = min(m,nums[i]*2);
            }
        }
        int ans = INT_MAX;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-m);
            if(top%2!=0){
                break;
            }
            m = min(m,top/2);
            pq.push(top/2);
        }
        return ans;
    }
};
