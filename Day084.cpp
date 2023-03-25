// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// Return the number of pairs of different nodes that are unreachable from each other.
  
// Constraints:

// 1 <= n <= 10^5
// 0 <= edges.length <= 2 * 10^5
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated edges.

class Solution {
public:
    typedef long long ll;
    void dfs(vector<int> adj[], int node , vector<int>&vis, int &c){
        c++;
        vis[node] =1;
        for(auto a : adj[node]){
            if(!vis[a]){
                dfs(adj,a,vis,c);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto a : edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> vis(n,0);
        ll ans=0, su=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis,c);
                ans += su*c;
                su +=c;
                c=0;
            }
        }
        return ans;
    }
};
