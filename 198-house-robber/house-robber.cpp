class Solution {
public:
    int rob(vector<int>& nums) {
        //tabulation
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        //bottom up
        for (int i = 1; i < n; i++) {
            //same pick and not pick method but from bottom up using tabulation method
            int pick = nums[i];
            if (i > 1) pick += dp[i - 2];
            int notPick = dp[i - 1];
            
            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }
};