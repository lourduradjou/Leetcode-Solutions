class Solution {
public:
    int rev(int num) {
        int reversedNumber = 0;
        while(num > 0) {
            reversedNumber = reversedNumber * 10 + num % 10;
            num = num / 10;
        }
        return reversedNumber;
    }
    int countNicePairs(vector<int>& nums) {
        int cnt = 0;
        const int mod = 1e9+7;

        unordered_map<int,int> mpp;

        for(auto it: nums) {
            cnt = ( (cnt + mpp[it - rev(it)]++) % mod);
        }
        return cnt;
    }
};