class Solution {
private:
    vector<int> dp;
    int n, k;

    int solve(int ind, vector<int> &arr) {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int maximumValue = 0, ans = 0;
        for(int j = ind; j < min(n, ind + k); j++) {
            maximumValue = max(maximumValue, arr[j]);
            ans = max(ans, (j - ind + 1) * maximumValue + solve(j + 1, arr));
        }

        return dp[ind] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        this->k = k;
        dp = vector<int> (n, -1);
        return solve(0, arr);
    }
};