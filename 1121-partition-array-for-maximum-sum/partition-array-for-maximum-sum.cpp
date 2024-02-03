class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int ind = n-1; ind >= 0; ind--) {
            int maxValue = 0;
            for(int j = ind; j < min(n, ind + k); j++) {
                maxValue = max(maxValue, arr[j]);
                dp[ind] = max(dp[ind], (j - ind + 1) * maxValue + dp[j+1]);
            }
        }

        return dp[0];
    }
};