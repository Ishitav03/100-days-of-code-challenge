// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Constraints:

// 1 <= s.length <= 10^4
// s consists of parentheses only '()[]{}'.


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]); 
            else{
                if(st.empty()||(s[i]==')'&& st.top()!='(')||
            (s[i]=='}'&& st.top()!='{')||
            (s[i]==']'&& st.top()!='['))
                return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
