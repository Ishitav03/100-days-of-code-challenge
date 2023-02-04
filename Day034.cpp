//6. Zigzag Conversion
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);


//Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int len =s.length();
        string *str = new string[numRows];

        int row = 0, step = 1;
        for (int i = 0; i < len; ++i){
            str[row].push_back(s[i]);
            if (row == 0) step = 1;
            else if (row == numRows-1) step = -1;
            row += step;
        }

        s.clear();
        for (int j = 0; j < numRows; ++j){
            s.append(str[j]);
        }
        delete[] str;
        return s;
    }
};
