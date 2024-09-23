class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        //tabulation
        //base case
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) dp[0][target] = target / coins[0];
            else dp[0][target] = 1e8;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notPick = dp[ind-1][target];
                int pick = 1e8;
                if (coins[ind] <= target) {
                    pick = 1 + dp[ind][target - coins[ind]];
                }

                dp[ind][target] = min(pick, notPick);
            }
        }

        int ans = dp[n-1][amount];
        return ans >= 1e8 ? -1: ans;
    }
};