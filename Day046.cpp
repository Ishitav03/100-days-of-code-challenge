//989. Add to Array-Form of Integer
//The array-form of an integer num is an array representing its digits in left to right order.
// For example, for num = 1321, the array form is [1,3,2,1].
// Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
  
  
//   Constraints:

// 1 <= num.length <= 10^4
// 0 <= num[i] <= 9
// num does not contain any leading zeros except for the zero itself.
// 1 <= k <= 10^4


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        for(int i=n-1;i>=0 && k>0;i--){
            num[i]+=k;
            k=num[i]/10;
            num[i]%=10;
        }
        while(k>0){
            num.insert(num.begin(),k%10);
            k/=10;
        }
        return num;
    }
};
