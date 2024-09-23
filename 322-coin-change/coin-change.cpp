class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        //tabulation
        //base case
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) prev[target] = target / coins[0];
            else prev[target] = 1e8;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notPick = prev[target];
                int pick = 1e8;
                if (coins[ind] <= target) {
                    pick = 1 + cur[target - coins[ind]];
                }

                cur[target] = min(pick, notPick);
            }
            prev = cur;
        }

        int ans = prev[amount];
        return ans >= 1e8 ? -1: ans;
    }
};