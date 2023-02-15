//2477. Minimum Fuel Cost to Report to the Capital
//There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

// There is a meeting for the representatives of each city. The meeting is in the capital city.

// There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

// A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

// Return the minimum number of liters of fuel to reach the capital city.
  
  
//   Constraints:

// 1 <= n <= 10^5
// roads.length == n - 1
// roads[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// roads represents a valid tree.
// 1 <= seats <= 10^5


class Solution {
public:
    long res=0;
    int s;

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size() + 1); 
        s = seats;
        for (vector<int>& r: roads) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }
        dfs(0, 0, graph);
        return res;
    }

    int dfs(int i, int prev, vector<vector<int>>& graph, int people = 1) {
        for (int& x: graph[i]) {
            if (x == prev) continue;
            people += dfs(x, i, graph);
        }
        if (i != 0) res += (people + s - 1) / s;
        return people;
    }
};
