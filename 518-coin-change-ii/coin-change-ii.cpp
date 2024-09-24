class Solution {
private:
    int funcSolve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target % coins[0] == 0) return 1;
            else return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notPick = 0 + funcSolve(ind - 1, target, coins, dp);

        int pick = 0;
        if (coins[ind] <= target) {
            pick = funcSolve(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return funcSolve(n-1, amount, coins, dp);
    }
};