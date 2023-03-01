//912. Sort an Array
// Given an array of integers nums, sort the array in ascending order and return it.
// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
  
  
//  Constraints:

// 1 <= nums.length <= 5 * 10^4
// -5 * 104 <= nums[i] <= 5 * 10^4


void sort(vector<int>& v, int n){
        if(n<2) return;
        vector<int> left;
        vector<int> right;

        int mid=n/2;
        //storing left and right parts of the array
        for(int i=0;i<n;i++){
            if (i < mid) left.push_back(v[i]);
            else right.push_back(v[i]);
        }
        sort(left, left.size());
        sort(right,right.size());

        mergeArr(v,left,right);
    }

    void mergeArr(vector<int>&v, vector<int>& left, vector<int>& right){
        int i=0,j=0,k=0;
        while (i<left.size() && j<right.size()){
            if(left[i]<=right[j]){ 
                v[k]=left[i];
                i++;
            }
            else {
                v[k]=right[j];
                j++;
            } k++;
        }

        while(i<left.size()){
            v[k]=left[i];
            i++;
            k++;
        }
        while(j<right.size()){
            v[k]=right[j];
            j++;
            k++;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums;
        sort(nums,n);
        return nums;   
    }
};
