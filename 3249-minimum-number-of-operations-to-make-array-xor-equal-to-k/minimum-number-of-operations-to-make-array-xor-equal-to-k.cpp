class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            xorNum ^= nums[i];
        }
        int cnt = 0;

        bitset<32> A(xorNum), B(k);
        for (int i = 0; i < 32; i++) {
            if (A[i] != B[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};