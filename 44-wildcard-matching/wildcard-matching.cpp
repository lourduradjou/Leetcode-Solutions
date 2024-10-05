class Solution {
    private:
        int isAllStars(string& str, int j) {
            for (int i = 1; i <= j; i++) {
                if (str[i-1] != '*') {
                    return false;
                }
            }
            return true;
        }

    public:
        bool isMatch(string s2, string s1) {
            int n = s1.size();
            int m = s2.size();

            vector<bool> prev(m+1, false);
            vector<bool> cur(m+1, false);

            //base cases
            prev[0] = true;

            for (int ind1 = 1; ind1 <= n; ind1++) {
                cur[0] = isAllStars(s1, ind1);
                
                for (int ind2 = 1; ind2 <= m; ind2++) {
                    if (s1[ind1-1] == s2[ind2-1] || s1[ind1-1] == '?') //incase match move back 
                        cur[ind2] = prev[ind2 - 1];
                    else if (s1[ind1-1] == '*') {
                        //either don't consider the * and move on 
                        // or consider the * one by one
                        cur[ind2] = cur[ind2 - 1] || prev[ind2];
                    }
                    else
                        cur[ind2] = false;
                }
                prev = cur;
            }

            return prev[m];
        }
};