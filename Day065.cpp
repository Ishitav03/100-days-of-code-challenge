// 1539. Kth Missing Positive Number
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.
  
//   Constraints:

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// arr[i] < arr[j] for 1 <= i < j <= arr.length


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (auto a : arr) if (a <= k) k++;
        return k;
    }
};
