//2244. Minimum Rounds to Complete All Tasks
//You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.
//Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        int res = 0, freq1;
        for (int a: tasks)
            ++count[a];
        for (auto& i: count) {
            if (i.second == 1) return -1;
            res+= (i.second + 2)/3;
        }
        return res;
    }
};
