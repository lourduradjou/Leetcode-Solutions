class Solution {
private:
    int findCoinChange(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        //base case
        if (ind == 0) {
            if (target % coins[ind] == 0) return target / coins[ind];
            else return 1e8;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notPick = findCoinChange(ind-1, target, coins, dp);
        int pick = 1e8;
        if (coins[ind] <= target) {
            pick = 1 + findCoinChange(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = min(notPick, pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = findCoinChange(n-1, amount, coins, dp);
        return ans >= 1e8 ? -1: ans;
    }
};