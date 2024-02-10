class Solution {
private:
    vector<vector<int>> dp;
    int isPalindrome(string s , int i , int j ) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = (s[i] == s[j]) ? isPalindrome(s, i+1, j-1) : 0;
    }

public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        dp = vector<vector<int>> (n, vector<int> (n, -1));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                count += isPalindrome(s, i, j);//;
            }
        }
        return count;
    }
}; 