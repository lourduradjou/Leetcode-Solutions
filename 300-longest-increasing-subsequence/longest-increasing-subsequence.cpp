class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        //using dp subsequence pick and not pick pattern this could be solved easily
        //with the help of storing the previous to get the increasign subsequence
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int prev = ind-1; prev >= -1; prev--) {
                int maxi = 0;
                maxi = dp[ind + 1][prev+1];
                if (prev == -1 || nums[ind] > nums[prev]) {
                    maxi = max( maxi, 1 + dp[ind + 1][ind + 1]);
                }
                dp[ind][prev+1] = maxi;
            }
        }

        return dp[0][0];
    }
};