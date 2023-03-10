//1137. N-th Tribonacci Number
//The Tribonacci sequence Tn is defined as follows: 
//T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
//Given n, return the value of Tn

//Constraints:

// 0 <= n <= 37
// The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.


class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int T0 = 0, T1 = 1, T2 = 1, T3 = T0 + T1 + T2;
        while (n-- > 2) {
            T3 = T0 + T1 + T2, T0 = T1, T1 = T2, T2 = T3;
        }
        return T2;
    }
};
