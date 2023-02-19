//226. Invert Binary Tree
//Given the root of a binary tree, invert the tree, and return its root.


//Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        }
        return root;
    }
};
