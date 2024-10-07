class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //simple solution is the add up the upward profit arrow, rather then 
        //considering the negative downward arrows into our profits collection...
        // simple two plot is enough to understand the logic (witout dp appraoch)
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i-1]) {
                profit += (prices[i] - prices[i-1]);
            }
        }
        
        return profit;
    }
};