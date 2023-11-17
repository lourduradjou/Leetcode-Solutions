class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int minimizedMaxSum = INT_MIN;
        int left = 0, right = size-1;

        while(left < right) {
            int currSum = nums[left++] + nums[right--];
            minimizedMaxSum = max(minimizedMaxSum, currSum);
        }
        
        return minimizedMaxSum;
    }
};