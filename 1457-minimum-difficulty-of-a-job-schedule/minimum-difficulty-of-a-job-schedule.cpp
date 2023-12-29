class Solution {
public:
    int dp[300][11][300];
    int helper(int ind, int n, vector<int>& jd, int d, int maxi_ind){
        if(d < 1)
            return 1e9;
        if(ind == n)
            return d == 1 ? jd[maxi_ind] : 1e9;
        if(dp[ind][d][maxi_ind] != -1)
            return dp[ind][d][maxi_ind];
        int mini = 1e9, tmp_ind = maxi_ind;
        if(jd[ind] > jd[maxi_ind])
            tmp_ind = ind;
        mini = min(mini, helper(ind + 1, n, jd, d, tmp_ind));
        if(ind > 0)
            mini = min(mini, jd[maxi_ind] + helper(ind + 1, n, jd, d - 1, ind));
        return dp[ind][d][maxi_ind] = mini;
    }

    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n < d)
            return -1;
        memset(dp, -1, sizeof(dp));
        return helper(0, n, jd, d, 0);
    }
};