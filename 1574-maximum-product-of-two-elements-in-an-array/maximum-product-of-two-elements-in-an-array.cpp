class Solution {
public:
    int maxProduct(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int size = nums.size();

      int ans = (nums[size-1] - 1) * (nums[size-2] - 1);
      return ans;
    }
};