class Solution {
private:
    int func(vector<int> &prices, int ind, int isAllowedToBuy, vector<vector<int>>& dp) {
        if (ind == prices.size()) 
            return 0;
        
        if (dp[ind][isAllowedToBuy] != -1) 
            return dp[ind][isAllowedToBuy];

        int profit = 0;
        if (isAllowedToBuy) {
            //we have to choice now, either to buy the stocks and move
            // or not to buy the stock but move further
            profit = max( 
                        (-prices[ind] + func(prices, ind+1, 0, dp)), //bought the stock
                        (0 +  func(prices, ind+1, 1, dp)) // not bought the stock
            );
        }
        else {
            profit = max( 
                        (prices[ind] + func(prices, ind+1, 1, dp)), //sold the stock
                        (0 +  func(prices, ind+1, 0, dp)) // not sold the stock
            );
        }

        return dp[ind][isAllowedToBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        //using recursion + memoization 
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return func(prices, 0, 1, dp); // 1 means allowed to buy, 0 means allowed to sell;
    }
};