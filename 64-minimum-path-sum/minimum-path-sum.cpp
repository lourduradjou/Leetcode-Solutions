class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid) {
        if (i == 0 && j == 0) return grid[i][j];
        if (i < 0 || j < 0) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int left = grid[i][j] + solve(i, j-1, dp, grid);
        int top = grid[i][j] + solve(i-1, j, dp, grid);


        return dp[i][j] = min(left, top);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return solve(m-1, n-1, dp, grid);
    }
};