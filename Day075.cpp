// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
  
// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;

        int ip = inorder.size() - 1;
        int pp = postorder.size() - 1;

        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        TreeNode* root = new TreeNode(postorder[pp]);
        st.push(root);
        pp--;

        while (pp >= 0) {
            while (!st.empty() && st.top()->val == inorder[ip]) {
                prev = st.top();
                st.pop();
                ip--;
            }
            TreeNode* newNode = new TreeNode(postorder[pp]);
            if (prev != nullptr) prev->left = newNode;
            else if (!st.empty()) {
                TreeNode* currTop = st.top();
                currTop->right = newNode;
            }
            st.push(newNode);
            prev = nullptr;
            pp--;
        }
        return root;
    }
};
