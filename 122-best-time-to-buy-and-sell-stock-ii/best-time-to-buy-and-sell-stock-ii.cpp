class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //using recursion + memoization 
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> cur(2, 0);

        
        for (int ind = n-1; ind >= 0; ind--) {
            for (int isAllowedToBuy = 0; isAllowedToBuy < 2; isAllowedToBuy++) {
                int profit = 0;
                if (isAllowedToBuy) {
                    //we have to choice now, either to buy the stocks and move
                    // or not to buy the stock but move further
                    profit = max( 
                                (-prices[ind] + next[0]), //bought the stock
                                (0 +  next[1]) // not bought the stock
                    );
                }
                else {
                    profit = max( 
                                (prices[ind] + next[1]), //sold the stock
                                (0 +  next[0]) // not sold the stock
                    );

                }

                cur[isAllowedToBuy] = profit;
            }
            next = cur;
        }
        return next[1]; // 1 means allowed to buy, 0 means allowed to sell;
    }
};