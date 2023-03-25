// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.

  

// Constraints:

// 2 <= n <= 5 * 10^4
// connections.length == n - 1
// connections[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n) , bk(n);
        vector<int> vis(n,0);
        vis[0] =1;
        for(auto a : connections){
            adj[a[0]].push_back(a[1]);
            bk[a[1]].push_back(a[0]);
        }
        int ans=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int a = q.front();
            vis[a] =1;
            q.pop();
            for( int no : adj[a]){
                if(!vis[no]){
                    ans++;
                    q.push(no);
                }
            }
            for( int no : bk[a]){
                if(!vis[no]){
                    q.push(no);
                }
            }
        }
        return ans;
    }
};
