// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
  
  
//   Constraints:

// 1 <= prices.length <= 10^5
// 0 <= prices[i] <= 10^4


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp =INT_MAX,p,res=0;        
        for(int i = 0; i < prices.size(); i++){
            cp = min(prices[i],cp);
            p= prices[i] - cp;
            res = max(p,res);
        }
        return res;
    }
};
