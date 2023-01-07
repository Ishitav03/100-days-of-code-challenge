//944. Delete Columns to Make Sorted
//You are given an array of n strings strs, all of the same length.

//The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:
//abc, bce, cae
//You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.
//Return the number of columns that you will delete.

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delete_count=0;
        int row = strs.size();
        int col = strs[0].size();
        
        for(int j=0; j<col; j++){
            for(int i=0; i<row-1; i++){
                if(strs[i][j]>strs[i+1][j]){
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }
};
