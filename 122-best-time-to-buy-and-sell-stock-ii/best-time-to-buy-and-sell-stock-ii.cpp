class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //using recursion + memoization 
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        
        for (int ind = n-1; ind >= 0; ind--) {
            for (int isAllowedToBuy = 0; isAllowedToBuy < 2; isAllowedToBuy++) {
                int profit = 0;
                if (isAllowedToBuy) {
                    //we have to choice now, either to buy the stocks and move
                    // or not to buy the stock but move further
                    profit = max( 
                                (-prices[ind] + dp[ind+1][0]), //bought the stock
                                (0 +  dp[ind+1][1]) // not bought the stock
                    );
                }
                else {
                    profit = max( 
                                (prices[ind] + dp[ind+1][1]), //sold the stock
                                (0 +  dp[ind+1][0]) // not sold the stock
                    );
                }

                dp[ind][isAllowedToBuy] = profit;
            }
        }
        return dp[0][1]; // 1 means allowed to buy, 0 means allowed to sell;
    }
};