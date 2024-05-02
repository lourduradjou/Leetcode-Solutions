class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxNum = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxNum && st.find(-nums[i]) != st.end())
                maxNum = nums[i];
        }

        return maxNum;
    }
};