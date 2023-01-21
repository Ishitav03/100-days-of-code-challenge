//93. Restore IP Addresses
//A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.


// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.


class Solution {
public:
    bool valid(string s){
        if(s.size()==1){
            return true;
        }
        if(s.size()>3||s[0]=='0'){
            return false;
        }
        if(stoi(s)>255){
            return false;
        }
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()>12){
            return res;
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(i+j+k<s.size() && i+j+k+3>=s.size()){
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(j+i,k);
                        string d=s.substr(i+j+k);
                        if(valid(a)  && valid(b) && valid(c) && valid(d)){
                            res.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        return res;
    }
    
};
