class Solution {
private:
    int findSubArrayCounts(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        
        int l = 0, r = 0;
        int n = nums.size();
        int maxCount = 0;
        long long sum = 0;
        unordered_map<int,int> mpp;

        while (r < n) {
            mpp[nums[r]]++;

            while (mpp.size() > goal && l < n) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            maxCount += (r - l + 1);
            r++;
        }

        return maxCount;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findSubArrayCounts(nums, k) - findSubArrayCounts(nums, k - 1);
    }
};