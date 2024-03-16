class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int leftSum = (i > 0) ? prefixSum[i-1] : 0;
            int rightSum = prefixSum[n-1] - prefixSum[i];
            
            //cout<<leftSum<<" "<<rightSum<<endl;
            ans[i] = abs(leftSum - rightSum);
        }

        return ans;
    }
};