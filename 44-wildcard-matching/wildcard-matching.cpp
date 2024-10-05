class Solution {
    public:
        bool isMatch(string s1, string s2) {
            int n = s1.size();
            int m = s2.size();

            vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));

            //base cases
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++) {
                dp[i][0] = false;
            }
            for (int j = 1; j <= m; j++) {
                dp[0][j] = true;
                for (int i = 1; i <= j; i++) {
                    if (s2[i-1] != '*') {
                        dp[0][j] = false;
                        break;
                    }
                }
            }

            for (int ind1 = 1; ind1 <= n; ind1++) {
                for (int ind2 = 1; ind2 <= m; ind2++) {
                    if (s1[ind1-1] == s2[ind2-1] || s2[ind2-1] == '?') //incase match move back 
                        dp[ind1][ind2] = dp[ind1 - 1][ ind2 - 1];
                    else if (s2[ind2-1] == '*') {
                        //either don't consider the * and move on 
                        // or consider the * one by one
                        dp[ind1][ind2] = dp[ind1][ind2 - 1] || dp[ind1 - 1][ind2];
                    }
                    else
                        dp[ind1][ind2] = false;
                }
            }

            return dp[n][m];
        }
};