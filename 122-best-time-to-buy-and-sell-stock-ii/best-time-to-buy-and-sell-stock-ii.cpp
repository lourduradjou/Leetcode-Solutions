class Solution {
private:
    int solve (int i, int can_I_Buy, int &n, vector<int> &prices,
     vector<vector<int>> &dp) {
        if (i == n)
            return 0;

        if (dp[i][can_I_Buy] != -1)
            return dp[i][can_I_Buy];
        int profit = 0;

        if (can_I_Buy) {
            //there will be two options where i can buy or i can skip
            //for this specific i th index
            int take = -prices[i] + solve(i + 1, 0, n, prices, dp);
            int skip = 0 + solve(i + 1, 1, n, prices, dp);
            profit = max(take, skip);
        } 
        else {
            int sell = prices[i] + solve(i + 1, 1, n, prices, dp);
            int notSelled = 0 + solve(i + 1, 0, n, prices, dp);
            profit = max(sell, notSelled);
        }

        return dp[i][can_I_Buy] = profit;
     }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        return solve( 0, 1, n, prices, dp);
    }
};