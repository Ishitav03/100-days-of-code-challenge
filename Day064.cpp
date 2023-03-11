// 1345. Jump Game IV
// Given an array of integers arr, you are initially positioned at the first index of the array.

// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.
  
//   Constraints:

// 1 <= arr.length <= 5 * 10^4
// -10^8 <= arr[i] <= 10^8


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>m;
        for (int i=0;i<n;i++) 
            m[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int qs = q.size();
            while(qs--)
            {
                int curr = q.front();
                q.pop();
                if (curr == n-1) return steps;
                if (curr+1<n && !visited[curr+1]){
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                if (curr- 1 >= 0 && !visited[curr- 1]){
                    visited[curr- 1] = true;
                    q.push(curr- 1);
                }
                for (int newind : m[arr[curr]]){                                
                    if (!visited[newind]) 
                    {
                        visited[newind] = true;
                        q.push(newind);
                    }
                }                
                m[arr[curr]].clear();    
            }
            steps++;
        }
        return -1;
    }
};
