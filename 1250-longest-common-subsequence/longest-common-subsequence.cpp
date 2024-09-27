class Solution {
public:
    int lcs(int ind1, int ind2, string& str1, string& str2, vector<vector<int>>& dp) {
        if (ind1 == 0 || ind2 == 0) {
            return 0;
        }

        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        if (str1[ind1-1] == str2[ind2-1]) {
            return 1 + lcs(ind1-1, ind2-1, str1, str2,dp);
        }

        return dp[ind1][ind2] = max(lcs(ind1-1, ind2, str1, str2,dp), lcs(ind1, ind2-1, str1, str2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);

        //base cases for ind1 and ind2
        for (int j = 0; j <= m; j++) prev[j] = 0;

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1-1] == text2[ind2-1]) {
                    cur[ind2] =  1 +prev[ind2-1];
                }
                else {
                    cur[ind2] = max(prev[ind2], cur[ind2-1]);
                }    
            }
            prev = cur;
        }

        return prev[m];
    }
};