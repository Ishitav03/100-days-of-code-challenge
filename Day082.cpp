// 1319. Number of Operations to Make Network Connected
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
  
  
//   Constraints:

// 1 <= n <= 10^5
// 1 <= connections.length <= min(n * (n - 1) / 2, 10^5)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.
  
  
class Solution {
    void dfs(vector<int> adj[], vector<bool> &visited, int src) {
        visited[src] = true;
        for(int i : adj[src]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
    }
        
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if(len< n-1) return -1;
        vector<int> adj[n];
        for(auto v : connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i=0; i<n; i++)
        if(!visited[i]){
            dfs(adj, visited, i);
            ans++;
        }
        return ans - 1;
    }
};
