class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0);
        vector<int> next1(2, 0);
        vector<int> next2(2, 0);


        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                if (buy) {
                    //case is to buy , either buy it or move without buying
                    //buy it
                    cur[buy] = max(
                        -prices[ind] + next1[0],
                        0 + next1[1]
                        );
                } else {
                    cur[buy] = max(
                        prices[ind] + next2[1],
                        0 + next1[0]
                        );
                }
            }
            next2 = next1;
            next1 = cur;
        }
        return cur[1];
    }
};