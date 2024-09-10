class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //here they asking for min rather than max, same 2d dp
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        //initialization
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int leftDia = 1e8, rightDia = 1e8;
                int up = matrix[i][j] + dp[i-1][j];
                if(j > 0) leftDia = matrix[i][j] + dp[i-1][j-1];
                if(j < n-1) rightDia = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min({up, leftDia, rightDia});
            }
        }

        int mini = 1e8;
        
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[m-1][j]);
        }

        return mini;
    }
};