//926. Flip String to Monotone Increasing
//A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

//You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

//Return the minimum number of flips to make s monotone increasing.


// Constraints:

// 1 <= s.length <= 10^5
// s[i] is either '0' or '1'.



class Solution {
public:
    int minFlipsMonoIncr(const std::string& S, int counter_one  = 0, int counter_flip = 0) {
        for (auto ch : S) {
            if (ch == '1') {
                ++counter_one;
            } else {
                ++counter_flip;
            }
            counter_flip = std::min(counter_one, counter_flip);
        }
        return counter_flip;
    }
};
