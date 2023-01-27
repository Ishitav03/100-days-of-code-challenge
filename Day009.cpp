// 144. Binary Tree Preorder Traversal
// Given the root of a binary tree, return the preorder traversal of its nodes' values.


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root==NULL) return preorder;

        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (root) {
                preorder.push_back(root -> val);
                if (root -> right) {
                    st.push(root -> right);
                }
                root = root -> left;
            } else {
                root = st.top();
                st.pop();
            }
        }
        return preorder;
    }
};
