class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int cnt = 0, preSum = 0;

        for(auto it: nums) {
            preSum += it;
            int removeNumber = preSum - k;
            cnt += mpp[removeNumber];
            mpp[preSum]++;
        }

        return cnt;
    }
};