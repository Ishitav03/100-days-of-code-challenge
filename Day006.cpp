//1833. Maximum Ice Cream Bars
//It is a sweltering summer day, and a boy wants to buy some ice cream bars.
//At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
//Return the maximum number of ice cream bars the boy can buy with coins coins.

//Note: The boy can buy the ice cream bars in any order.

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int i=0,count=0;
        sort(costs.begin(),costs.end());
        while(i<costs.size()){
            if(coins-costs[i]>=0){
                coins-=costs[i];
                count++;
            }
            i++;
        }
        return count;
    }
};
