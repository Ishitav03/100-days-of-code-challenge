// 983. Minimum Cost For Tickets
// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.
  
//   Constraints:

// 1 <= days.length <= 365
// 1 <= days[i] <= 365
// days is in strictly increasing order.
// costs.length == 3
// 1 <= costs[i] <= 1000
  
  
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int cost = 0;
        queue<pair<int, int>> last7, last30;

        for (auto d : days) {
            while (!last7.empty() && last7.front().first + 7 <= d) last7.pop();
            while (!last30.empty() && last30.front().first + 30 <= d) last30.pop();
            
            last7.push({ d, cost + costs[1] });
            last30.push({ d, cost + costs[2] });
            
            cost = min({ cost + costs[0], last7.front().second, last30.front().second });
        }
        return cost;
    }
};
