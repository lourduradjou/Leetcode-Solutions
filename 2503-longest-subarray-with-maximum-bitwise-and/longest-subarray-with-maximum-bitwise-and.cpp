class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int ans = 0;

        int longestLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxValue) 
                ans = max(ans, ++longestLength);
            else
                longestLength = 0;
        }

        return ans;
    }
};