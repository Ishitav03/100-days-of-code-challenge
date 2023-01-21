//491. Non-decreasing Subsequences
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.


// Constraints:

// 1 <= nums.length <= 15
// -100 <= nums[i] <= 100


class Solution {
public:
    void func(int idx,vector<int>&nums,vector<int>&a,set<vector<int>>&res){
        int n=nums.size();
        if(idx>=n){
            if(a.size()>=2){
                res.insert(a);
            }
            return ;
        }
        if(!a.size()||nums[idx]>=a.back()){
            a.push_back(nums[idx]);
            func(idx+1,nums,a,res);
            a.pop_back();
        }
        func(idx+1,nums,a,res); 
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>res;
        func(0,nums,temp,res);
        return vector(res.begin(),res.end());
    }
};
