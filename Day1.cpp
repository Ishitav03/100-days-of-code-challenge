//984. String Without AAA or BBB
//Given two integers a and b, return any string s such that: s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
//The substring 'aaa' does not occur in s, and
//The substring 'bbb' does not occur in s.


class Solution {
public:
    string strWithout3a3b(int a, int b) {        
        if(a == 0) return string(b, 'b');
        else if(b == 0) return string(a, 'a');
        else if(a == b) return "ab" + strWithout3a3b(a - 1, b- 1);
        else if(a > b) return "aab" + strWithout3a3b(a - 2, b- 1);
        else return strWithout3a3b(a-1,b-2) + "abb";
    }
}; 
