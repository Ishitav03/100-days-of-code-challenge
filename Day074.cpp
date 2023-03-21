// 958. Check Completeness of a Binary Tree
// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

//  Constraints:

// The number of nodes in the tree is in the range [1, 100].
// 1 <= Node.val <= 1000
  
  
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count(TreeNode* root){
        if (root == nullptr) return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool check(TreeNode* root,int ind, int total){
        if(root == nullptr) return true;    
        if(ind >= total) return false;    
        return check(root->left, 2*ind+1, total) && check(root->right, 2*ind+2, total);
    }
    bool isCompleteTree(TreeNode* root) {
        int total=count(root);
        return check(root,0,total);
    }
};
