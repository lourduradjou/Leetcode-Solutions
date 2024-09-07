class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n,-1));
        for (int i = n-1; i >= 0; i--) {
            dp[n-1][i] = triangle[n-1][i];
        }
        //we tried to go from top to bottom in memo with 0 to the bottom 
        //in tabu it is the opposite 
        for (int i = n-2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                if (i == n-1) dp[i][j] = triangle[i][j];
                else {
                    int down = triangle[i][j] + dp[i+1][j];
                    int diaRight = triangle[i][j] + dp[i+1][j+1];

                    dp[i][j] = min(down, diaRight);
                }
            }
        }

        return dp[0][0];
    }
};