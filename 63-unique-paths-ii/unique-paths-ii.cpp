class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid) {
        //conditions
        if (i >= 0 && j >=0 && grid[i][j] == 1) return 0;
        if (i == 0 && j ==0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j-1, dp, grid);
        int top = solve(i-1, j, dp, grid);

        return dp[i][j] = left + top;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, dp, obstacleGrid);
    }
};