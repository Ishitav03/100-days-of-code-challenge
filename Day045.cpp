//67. Add Binary
//Given two binary strings a and b, return their sum as a binary string.

//Constraints:

// 1 <= a.length, b.length <= 10^4
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.


class Solution {
public:
    string addBinary(string a, string b) {
        string res= "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        for (i,j; i >= 0 || j >= 0; i--, j--) {
                int m = (i >= 0 && a[i] == '1');
                int n = (j >= 0 && b[j] == '1');
                res = to_string((m + n + c) & 0x1) + res;
                c = (m + n + c) >> 1;
        }
        return c ? '1' + res : res;
    }
};
