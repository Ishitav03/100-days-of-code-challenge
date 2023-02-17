//104. Maximum Depth of Binary Tree
//Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


//Constraints:

//The number of nodes in the tree is in the range [0, 10^4].
//-100 <= Node.val <= 100


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int maxLeft = maxDepth(root->left)+1;
        int maxRight = maxDepth(root->right)+1;
        return max(maxLeft, maxRight);
    }
};
