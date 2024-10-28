class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        int maxi = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int prev = 0; prev < i; prev++) {
                if( nums[prev] < nums[i]) {
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
            maxi = max(maxi, dp[i]);//finally we need the maximum among them      
        }
        return maxi;
    }
};