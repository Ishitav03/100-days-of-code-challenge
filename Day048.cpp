//783. Minimum Distance Between BST Nodes
//Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

//Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 0 <= Node.val <= 10^5


class Solution {
public:
    int min_diff=INT_MAX;  
    int prev=-1;  
    void inOrder(TreeNode*root){
       if(!root)return;
       inOrder(root->left);
       if(prev>=0)
       min_diff=min(min_diff,root->val-prev);
       prev=root->val;
       inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)return 0;
        inOrder(root);
        return min_diff;
    }
    
};
