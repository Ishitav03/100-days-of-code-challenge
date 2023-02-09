//1470. Shuffle the Array
//Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

//Return the array in the form [x1,y1,x2,y2,...,xn,yn].


//Constraints:

// 1 <= n <= 500
// nums.length == 2n
// 1 <= nums[i] <= 10^3


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {        
        for(int i = n; i<nums.size(); i++) {
            nums[i] = (nums[i] << 10) | nums[i - n];
        }
        int ind = 0;
        for(int i = n; i <nums.size(); i++, ind += 2) {
            nums[ind] = nums[i] & 1023;
            nums[ind + 1] = nums[i] >> 10;
        }
        return nums;
    }
};
