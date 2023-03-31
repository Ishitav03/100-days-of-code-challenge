// 1402. Reducing Dishes
// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

//  Constraints:

// n == satisfaction.length
// 1 <= n <= 500
// -1000 <= satisfaction[i] <= 1000
  
  
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int n = satisfaction.size();
        int sum = 0, res=0;
        for (int i = 0; i < n; i++) {
            sum += satisfaction[i];
            if (sum < 0) break;
            res += sum;
        }
        return res;
    }
};
