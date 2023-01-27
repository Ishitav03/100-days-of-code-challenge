//2246. Longest Path With Different Adjacent Characters
//You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
//You are also given a string s of length n, where s[i] is the character assigned to node i.
//Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.

//Constraints:

// n == parent.length == s.length
// 1 <= n <= 105
// 0 <= parent[i] <= n - 1 for all i >= 1
// parent[0] == -1
// parent represents a valid tree.
// s consists of only lowercase English letters.


class Solution {
public:
    vector<int> child[100001];
    int res;
    int dfs(string &s, int curr_node)
    {
        if(child[curr_node].empty())return 1;
        int mx1 = 0, mx2 =0;
        for(auto &child_node : child[curr_node]){
            int len = dfs(s, child_node);
            res = max(res , len);
            if(s[curr_node] == s[child_node])continue;
            if(len > mx1){
                mx2 = mx1;
                mx1 = len;
            }
            else mx2 = max(mx2 , len);
        }
        res = max(res, 1 + mx1 + mx2);
        return 1 + mx1; //adding 1 to current node
    }
    int longestPath(vector<int>& parent, string s){
        int n = parent.size();
        for(int i=1;i<n;i++)child[parent[i]].push_back(i);
        res = 1;
        dfs(s,0);
        return res;
    }
};
