class Solution:
    def numDecodings(self, s: str) -> int:
        dp1 = 1 # corresponds to dp[n] = 1
        dp2 = 0 # coresponds to the next variable initialized with zero

        for i in range(len(s) - 1, -1, -1):
            curr = 0

            if s[i] != "0":
                curr = dp1
                if (i + 1) < len(s) and (s[i] == "1" or (s[i] == "2" and s[i+1] in "0123456")):
                    curr += dp2
            
            dp2 = dp1
            dp1 = curr
        
        return dp1