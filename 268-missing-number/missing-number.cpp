class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = 0, b = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            a ^= i;
            b ^= nums[i];
        }

        a ^= n;
        return a ^ b;
    }
};