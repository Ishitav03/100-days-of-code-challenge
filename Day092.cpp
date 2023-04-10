// 2300. Successful Pairs of Spells and Potions
// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

//  Constraints:

// n == spells.length
// m == potions.length
// 1 <= n, m <= 10^5
// 1 <= spells[i], potions[i] <= 10^5
// 1 <= success <= 10^^10


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {        
        int n = spells.size();
        vector<int> pairs(n, 0);
        int m = potions.size();

        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            int l = 0, r = m - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                long long product = (long long)spell * (long long)potions[mid];

                if (product >= success) r = mid - 1;
                else l = mid + 1;
            }
            pairs[i] = m - l;
        }
        return pairs;
    }
};
