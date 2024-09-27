class Solution {
public:
    int lcs(int ind1, int ind2, string& str1, string& str2, vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }

        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        if (str1[ind1] == str2[ind2]) {
            return 1 + lcs(ind1-1, ind2-1, str1, str2,dp);
        }

        return dp[ind1][ind2] = max(lcs(ind1-1, ind2, str1, str2,dp), lcs(ind1, ind2-1, str1, str2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lcs(n-1, m-1, text1, text2, dp);
    }
};