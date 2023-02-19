//103. Binary Tree Zigzag Level Order Traversal
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

//  Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        bool flag=true; // left to right traversal
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n= q.size();
            vector<int> row(n);
            
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();

                int pos= (flag)? i :(n-i-1);
                row[pos] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            flag=!flag;
            res.push_back(row);
        }
        return res;
    }
};
