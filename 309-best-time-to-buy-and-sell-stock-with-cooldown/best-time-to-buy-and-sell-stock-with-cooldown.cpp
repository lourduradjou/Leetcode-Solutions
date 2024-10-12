class Solution {
private:
    int findMaxProfit(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (ind >= n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            //case is to buy , either buy it or move without buying
            //buy it
            return dp[ind][buy] = max(
                -prices[ind] + findMaxProfit(ind + 1, 0, prices, n, dp),
                 0 + findMaxProfit(ind + 1, 1, prices, n, dp)
                );
        } else {
            return dp[ind][buy] = max(
                prices[ind] + findMaxProfit(ind + 2, 1, prices, n, dp),
                0 + findMaxProfit(ind + 1, 0, prices, n, dp)
                );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findMaxProfit(0, 1, prices, n, dp);
    }
};