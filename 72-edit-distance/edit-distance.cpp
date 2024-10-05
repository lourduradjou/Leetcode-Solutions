class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n = word1.size();
            int m = word2.size();

            vector<int> prev(m+1, 0);
            vector<int> cur(m+1, 0);

            //base cases for tabulation from memo code
            for (int j = 0; j <= m; j++) prev[j] = j;

            for (int ind1 = 1; ind1 <= n; ind1++) {
                cur[0] = ind1;
                for (int ind2 = 1; ind2 <= m; ind2++) {
                    if (word1[ind1-1] == word2[ind2-1]) 
                        cur[ind2] = prev[ind2-1]; //matching move back
                    else {
                         //insert, delete, replace operations are there
                        cur[ind2] = 1 + min( {cur[ind2-1], 
                        prev[ind2], prev[ind2-1]} );
                    } 
                }
                prev = cur;
            }

            return prev[m];
        }
};