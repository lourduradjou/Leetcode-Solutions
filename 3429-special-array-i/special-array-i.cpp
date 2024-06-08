class Solution {
private:
    string parity(int num) {
        if (num % 2 == 1)
            return "odd";
        else 
            return "even";
    }

public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if( parity(nums[i]) == parity(nums[i-1]) )
                return false;
        }

        return true;
    }
};