// 28. Find the Index of the First Occurrence in a String
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

//   Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.
  
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();
        int i=0, res=-1; 
        int n=needle.size();
        while(i<n1){
            auto itr=find(haystack.begin()+i,haystack.end(),needle[0]);
            int n=itr-haystack.begin();
            string s=haystack.substr(n,n2);
            if(s==needle){
                res=n; 
                break;
            }
            else{
                i++;
                continue;
            }
        }
        return res; 
    }
};
