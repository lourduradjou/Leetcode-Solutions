class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> dp(m, vector<int> (n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                    else {
                        int top = grid[i][j];
                        int left = grid[i][j];

                        if (i > 0) top += dp[i-1][j];
                        else top += 1e9;

                        if (j > 0) left += + dp[i][j-1];
                        else left += 1e9;

                        dp[i][j] = min(top, left);
                    }
                }
            }

            return dp[m-1][n-1];
        }
};