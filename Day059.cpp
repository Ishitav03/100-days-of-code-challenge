// 652. Find Duplicate Subtrees
// Given the root of a binary tree, return all duplicate subtrees.

// For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with the same node values.
  
  
//   Constraints:

// The number of the nodes in the tree will be in the range [1, 5000]
// -200 <= Node.val <= 200
  
  
class Solution {
public:
    unordered_map<string,int> s;
    vector<TreeNode*> v;
    string subtree(TreeNode* root){
        string r1="",
        r2="";
        if(root->right!=NULL) r2=r2+subtree(root->right);
        if(root->left!=NULL) r1=r1+subtree(root->left);
           
        string res =to_string(root->val)+","+r1+","+r2;
        if(s.find(res)!=s.end()){
            if(s[res]==1) v.push_back(root); 
            s[res]++;
        }
        else s[res]=1;
        return res;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string k=subtree(root);
        return v;
    }
};
