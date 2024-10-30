class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if ( arr[i] % arr[prev] == 0 && dp[i] < dp[prev] + 1 ) {
                    dp[i] = 1 + dp[prev]; //take the largest value
                    hash[i] = prev; //mark to print, if needed
                }
            }

            //markdown the last index to trace back
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            temp.push_back(arr[hash[lastIndex]]);
            lastIndex = hash[lastIndex];
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};