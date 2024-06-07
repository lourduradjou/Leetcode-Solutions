class Solution {
public:
    int rob(vector<int>& nums) {
        //tabulation
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        //bottom up
        for (int i = 1; i < n; i++) {
            //same pick and not pick method but from bottom up using tabulation method
            int pick = nums[i];
            if (i > 1) pick += prev2; //we are picking two steps back answer with prev2 variable here.. //pick += dp[i-2];
            int notPick = prev1;
            
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};