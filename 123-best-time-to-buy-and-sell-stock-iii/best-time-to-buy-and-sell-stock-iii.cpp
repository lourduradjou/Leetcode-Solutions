class Solution {
private:
    int findMaxProfit(int ind, int buy, int capacity, vector<int>& prices, int n, vector<vector<vector<int>>>& dp ) {
        if (capacity == 0) return 0;
        if (ind == n) return 0;

        if (dp[ind][buy][capacity] != -1) return dp[ind][buy][capacity];

        if (buy) {
            //in buy case we have two subcase either buy and move or don't
            return dp[ind][buy][capacity] = 
                    max( -prices[ind] + findMaxProfit(ind+1, 0, capacity, prices, n, dp)
                        , 0 + findMaxProfit(ind+1, 1, capacity, prices, n, dp) );
        }
        else {
            //in sell case we have two subcase either sell and move or don't
            return dp[ind][buy][capacity] = 
                    max( prices[ind] + findMaxProfit(ind+1, 1, capacity-1, prices, n, dp)
                        , 0 + findMaxProfit(ind+1, 0, capacity, prices, n, dp) );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2, vector<int> (3, -1)));

        return findMaxProfit(0, 1, 2, prices, n, dp);
    }
};