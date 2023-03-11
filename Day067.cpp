// 875. Koko Eating Bananas
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.
  
  
//   Constraints:

// 1 <= piles.length <= 10^4
// piles.length <= h <= 10^9
// 1 <= piles[i] <= 10^9


class Solution {
public:
    bool check(vector<int>& piles,int mid,int h){
        int count=0;
        for(int i=0;i<piles.size();++i){
            double temp=(double)piles[i]/(double)mid;
            if(temp>(int)temp) count+=(int)temp+1;
            else count+=temp;
        }
        if(count>h) return false;
        else return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mid, left=1, right=1e9+5,
        ans=0;
        while(left<right){
            mid=left+(right-left)/2;
            if(check(piles,mid,h)){
              ans=mid;
              right=mid;
            }else left=mid+1;
        }
        return ans;
    }
};
