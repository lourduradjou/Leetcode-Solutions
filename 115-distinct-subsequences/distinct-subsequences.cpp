class Solution {
public:
    const int MOD = 1e9 + 7;
    int numDistinct(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            prev[0] = 1;
            for (int j = m; j >= 1; j--) {
                if (s1[i-1] == s2[j-1]) {
                    prev[j] = (prev[j-1] + prev[j]) % MOD;
                }else {
                    prev[j] = prev[j];
                }    
            }
            //prev = cur;
        }

        return prev[m];
    }
};