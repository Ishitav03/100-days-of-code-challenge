// 427. Construct Quad Tree

// Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

// Return the root of the Quad-Tree representing the grid.

// Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

// A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

// val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
// isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
  
   

// Constraints:

// n == grid.length == grid[i].length
// n == 2x where 0 <= x <= 6

class Solution {
public:
   Node* solve(int l,int r,int t,int b, vector<vector<int>>& grid){
        if(l==r || t==b ){
            return new Node(grid[t][l],true);
        }
        Node* root= new Node(1,false);

        root->topLeft=solve(l,(r+l)/2,t,(b+t)/2,grid);
        root->topRight=solve(((r+l)/2)+1,r,t,(b+t)/2,grid);
        root->bottomLeft=solve(l,(r+l)/2,((b+t)/2)+1,b,grid);
        root->bottomRight=solve(((r+l)/2)+1,r,(b+t)/2+1,b,grid);

        if(root->topLeft->val == root->topRight->val && 
           root->topLeft->val == root->bottomLeft->val &&
           root->topLeft->val == root->bottomRight->val &&
           root->topLeft->isLeaf && root->topRight->isLeaf &&
           root->bottomLeft->isLeaf && root->bottomRight->isLeaf)
               return new Node(root->topLeft->val,true);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return solve(0,n-1,0,n-1,grid);
    }
};
