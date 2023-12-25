class Solution {
public:
    int solve(int i, string &s, int &n, vector<int> &dp){
        if(i == n){
            return 1; // out of bound (>26)
        }
        if(s[i] == '0'){
            return 0;  // np split
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int ans = solve(i+1, s, n, dp);

        if(i+1 < n){          // overflow check
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){   // 1_ or <=26 condition check
                ans += solve(i+2, s, n, dp);
            }   
        }
        return dp[i] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);

        return solve(0, s, n, dp);
    }

    //no idea about dp will surely try again after a month
};