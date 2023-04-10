// 1857. Largest Color Value in a Directed Graph
// There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

// You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

// Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
  
   

// Constraints:

// n == colors.length
// m == edges.length
// 1 <= n <= 10^5
// 0 <= m <= 10^5
// colors consists of lowercase English letters.
// 0 <= aj, bj < n

class Solution {
public:
    int largestPathValue(string c, vector<vector<int>>& edges) {
        vector<vector<int>> a(c.size()), cnt(c.size(), vector<int>(26));
        vector<int> indeg(c.size());
        for (auto &e: edges) {
            a[e[0]].push_back(e[1]);
            ++indeg[e[1]];
        }
        vector<int> q;
        for (int i = 0; i < c.size(); ++i)
            if (indeg[i] == 0) q.push_back(i);

        int res = 0, process = 0;
        while (!q.empty()) {
            vector<int> q1;
            for (auto i : q) {
                ++process;
                res = max(res, ++cnt[i][c[i] - 'a']);
                for (auto j : a[i]) {
                    for (auto k = 0; k < 26; ++k)
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    if (--indeg[j] == 0) q1.push_back(j);
                }
            }
            swap(q, q1);
        }
        return process != c.size() ? -1 : res;
    }
};
