//1626. Best Team With No Conflicts
//You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

//However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

//Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.


//Constraints:

// 1 <= scores.length, ages.length <= 1000
// scores.length == ages.length
// 1 <= scores[i] <= 10^6
// 1 <= ages[i] <= 1000


class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int s = scores.size();
        int dp[s], 
        res=0;
        
        vector<pair<int, int>> players;
        for(int i = 0; i <s; i++) 
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        
        for(int i = 0; i <s; i++) {
            dp[i] = players[i].second;
            for(int j = 0; j < i; j++) {
                if(players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
