class Solution {
public:
    int solve(int i, int j , int m, vector<vector<int>> &dp, vector<vector<int>> &triangle) {
        if (i == m-1) return triangle[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(i+1, j, m, dp, triangle);
        int diaMove = triangle[i][j] + solve(i+1, j+1, m, dp, triangle);

        return dp[i][j] = min(down, diaMove);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();;

        vector<vector<int>> dp(m, vector<int>(m,-1));

        return solve(0,0, m, dp, triangle);
    }
};