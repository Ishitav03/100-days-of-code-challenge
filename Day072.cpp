// // 101. Symmetric Tree
// // Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100
 

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
    bool check(TreeNode* n1, TreeNode* n2){
        if(!n1||!n2) return n1==n2;
        if(n1->val == n2->val) 
            return check(n1->left,n2->right)&& check(n1->right,n2->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root-> left,root->right);
    }
};
