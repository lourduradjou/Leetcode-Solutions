class Solution {
private:
    int solve(vector<int> &dp, vector<int> &nums, int n) {
        if (n == 0) return nums[0]; //first house value
        if (n < 0) return 0;

        if (dp[n] != -1) return dp[n];

        //pick or not pick method
        int pick = nums[n] + solve(dp, nums, n-2);//we pick the house money so lets move 2 steps

        int notPick = solve(dp, nums, n - 1);

        return dp[n] = max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {
        //memo + subsequence method we can try
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(dp, nums, n-1);
    }
};