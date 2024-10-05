class Solution {
private:
    int findMinDistance(int ind1, int ind2, string& str1, string& str2, vector<vector<int>>& dp) {
        if (ind1 == 0) return ind2;
        if (ind2 == 0) return ind1;

        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if (str1[ind1-1] == str2[ind2-1]) {
            return findMinDistance(ind1-1, ind2-1, str1, str2, dp); //matching move back
        }
        //insert, delete, replace operations are there
        return dp[ind1][ind2] = 1 + min( {findMinDistance(ind1, ind2-1,str1, str2, dp), 
        findMinDistance(ind1-1, ind2,str1, str2, dp), findMinDistance(ind1-1, ind2-1,str1, str2, dp)} );
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return findMinDistance(n, m, word1, word2, dp);
    }
};