//1011. Capacity To Ship Packages Within D Days
// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
  
  
//   Constraints:

// 1 <= days <= weights.length <= 5 * 10^4
// 1 <= weights[i] <= 500


class Solution {
public:
    bool shipping(vector<int>& weights, int days, int maxCapacity) {
        int curr_Days = 1, curr_Capacity = 0;
        for(int weight: weights) {
            if(weight > maxCapacity) return false;
            if(weight + curr_Capacity > maxCapacity) {
                curr_Days += 1;
                if(curr_Days > days) return false;
                curr_Capacity = weight;
            } else curr_Capacity += weight;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int capacity = 0, maxWeight = 0, sumWeights = 0;
        for(int weight : weights) {
            maxWeight = max(maxWeight, weight);
            sumWeights += weight;
        }
        int start = maxWeight, end = sumWeights;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(shipping(weights, days, mid)) {
                capacity = mid;
                end = mid - 1;
            } 
            else start = mid + 1; 
        }
        return capacity;
    }
};
