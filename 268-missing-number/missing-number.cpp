class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;

        return totalSum - accumulate(nums.begin(), nums.end(), 0);
    }
};