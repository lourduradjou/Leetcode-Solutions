class Solution {
public:
    vector<vector<int>> dp;
    int findPaths(int i, int j) {
        if(i == 0 && j == 0) {
            return 1;
        }
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int upCount = findPaths(i, j-1);
        int leftCount = findPaths(i-1, j);
        return dp[i][j] = (upCount + leftCount);
    }
    int uniquePaths(int m, int n) {
        //as recursion gives tle lets try bottom up ..
        //so down and right here will change as up and left..
        //so that at that point what are the possible moves we can find
        dp = vector<vector<int>> (m+1, vector<int>(n+1, -1));
        return findPaths(m-1, n-1);
    }
};