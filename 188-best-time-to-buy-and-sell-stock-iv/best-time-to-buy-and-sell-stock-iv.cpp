class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2 * k + 1, 0);
        vector<int> cur(2 * k + 1, 0);

        for (int ind = n-1; ind >= 0; ind--) {
            for (int ts = 2 * k - 1; ts >= 0; ts--) {
                 if (ts % 2 == 0) {
                    //buy case 
                    cur[ts] = max(-prices[ind] + after[ts+1], 0 + after[ts]);
                }
                else {
                    cur[ts] = max(prices[ind] + after[ts+1], 0 + after[ts]);
                }
            }
            after = cur;
        }
        return cur[0];
    }
};