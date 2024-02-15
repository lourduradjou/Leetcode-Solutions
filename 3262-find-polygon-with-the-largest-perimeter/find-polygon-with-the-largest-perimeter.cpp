class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long maximumPerimeter = INT_MIN;
        long long prefixSum = nums[0] + nums[1];

        for (long long i = 2; i < nums.size(); i++) {
            if (prefixSum > nums[i]) {
                maximumPerimeter = max(maximumPerimeter, prefixSum + nums[i]);
            }
            prefixSum += nums[i];
        }

        return (maximumPerimeter == INT_MIN) ? -1 : maximumPerimeter;
    }
};