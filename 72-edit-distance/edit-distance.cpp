class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n = word1.size();
            int m = word2.size();

            vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

            //base cases for tabulation from memo code
            for (int i = 0; i <= n; i++) dp[i][0] = i;
            for (int j = 0; j <= m; j++) dp[0][j] = j;

            for (int ind1 = 1; ind1 <= n; ind1++) {
                for (int ind2 = 1; ind2 <= m; ind2++) {
                    if (word1[ind1-1] == word2[ind2-1]) 
                        dp[ind1][ind2] = dp[ind1-1][ind2-1]; //matching move back
                    else {
                         //insert, delete, replace operations are there
                        dp[ind1][ind2] = 1 + min( {dp[ind1][ind2-1], 
                        dp[ind1-1][ind2], dp[ind1-1][ind2-1]} );
                    } 
                }
            }

            return dp[n][m];
        }
};