class Solution {
private:
    int findSubArrayCounts(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        
        int l = 0, r = 0;
        int n = nums.size();
        int maxCount = 0;
        long long sum = 0;

        while (r < n) {
            sum += (nums[r] % 2);

            while (sum > goal && l < n) {
                sum = sum - (nums[l] % 2);
                l++;
            }

            maxCount += (r - l + 1);
            r++;
        }

        return maxCount;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findSubArrayCounts(nums, k) - findSubArrayCounts(nums, k - 1);
    }
};