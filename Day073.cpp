// 129. Sum Root to Leaf Numbers
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.


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
    typedef long long ll;
    void dfs(TreeNode *root, ll &ans , ll tmp){
        if(root->left== NULL && root->right==NULL){
            tmp = tmp*10 + root->val;
            ans+=tmp;
            return;
        }
        tmp = tmp*10 + root->val;
        if(root->left) dfs(root->left,ans,tmp);
        if(root->right) dfs(root->right,ans,tmp);
    }

    int sumNumbers(TreeNode* root) {
        ll ans =0;
        dfs(root,ans,0);
        return int(ans);
    }
};
