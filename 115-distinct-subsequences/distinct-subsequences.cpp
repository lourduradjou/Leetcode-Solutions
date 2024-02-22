class Solution {
private:
      const int MOD = 1e9 + 7;
      int solve(int i, int j, string &s, string &t,
      int &n, int &m, vector<vector<int>> &dp) {
          if (i == n)
            return j == m ? 1 : 0;
          
          if (j >= m)
            return 1;
        
          if (dp[i][j] != -1)
            return dp[i][j];
          
          int notPick = solve(i+1, j, s, t, n, m, dp);
          int pick = 0;
          
          if (s[i] == t[j]) {
              pick = solve(i+1, j+1, s, t, n, m, dp);
          }
          
          return dp[i][j] = (pick + notPick) % MOD;
      }
      
public:
    int numDistinct(string s, string t) {
      int n = s.size(), m = t.size();
      vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));
      
      return solve(0, 0, s, t, n, m, dp);
    }
};