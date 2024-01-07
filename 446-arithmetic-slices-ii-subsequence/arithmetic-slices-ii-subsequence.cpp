class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long,int>>dp(n);
        int ans=0;

        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                long diff=(long)nums[i]-nums[j];
                if (diff>INT_MAX || diff<INT_MIN) continue;
                dp[i][diff]++;
                if (dp[j][diff]>0) {
                    dp[i][diff]+=dp[j][diff];
                    ans+=dp[j][diff];
                }
            }
        }

        // for(int i = 0; i < n; i++) {
        //     cout<<"Map " <<i<<endl;
        //     for(auto it: dp[i]) {
        //         cout<<"Map values is "<<it.first<<" freq is "<<it.second<<endl;
        //     }
        // }
        return ans;
    }
};