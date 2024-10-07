class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //storing the previous minimum and buying the maximum stock would give the highest profit
        int mini = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(prices[i], mini);
        }

        return profit;
    }
};