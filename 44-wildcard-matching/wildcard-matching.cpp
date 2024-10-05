class Solution {
private:
    int findMatch(int ind1, int ind2, string& s1, string& s2,vector<vector<int>>& dp) {
        if (ind1 == 0 && ind2 == 0) return true;
        if (ind2 == 0 && ind1 > 0) return false;
        if (ind1 == 0 && ind2 > 0) {
            //either all the characters in s1 shd be *(star) else return false 
            for (int i = 1; i <= ind2; i++) {
                if (s2[i-1] != '*')
                    return false;
            }
            return true;
        }

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if (s1[ind1-1] == s2[ind2-1] || s2[ind2-1] == '?') //incase match move back 
            return dp[ind1][ind2] = findMatch(ind1 - 1, ind2 - 1, s1, s2, dp);
        if (s2[ind2-1] == '*') {
            //either don't consider the * and move on 
            // or consider the * one by one
            return dp[ind1][ind2] = findMatch(ind1, ind2 - 1, s1, s2, dp) || findMatch(ind1 - 1, ind2, s1, s2, dp);
        }

        return dp[ind1][ind2] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return findMatch(n, m, s, p, dp);
    }
};