class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2 * k + 1, 0));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int ts = 2 * k - 1; ts >= 0; ts--) {
                 if (ts % 2 == 0) {
                    //buy case 
                    dp[ind][ts] = max(-prices[ind] + dp[ind+1][ts+1], 0 + dp[ind+1][ts]);
                }
                else {
                    dp[ind][ts] = max(prices[ind] + dp[ind+1][ts+1], 0 + dp[ind+1][ts]);
                }
            }
        }
        return dp[0][0];
    }
};