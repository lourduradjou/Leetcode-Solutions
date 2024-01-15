class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> playersWinningDetails;

        for(auto it: matches) {
            playersWinningDetails[it[0]];
            playersWinningDetails[it[1]]--;
        }

        vector<vector<int>> ans(2);
        for(auto it: playersWinningDetails) {
            if(it.second == 0)
                ans[0].push_back(it.first);
            else if(it.second == -1)
                ans[1].push_back(it.first);
        }


        return ans;
    }
};