class Solution {
public:
bool isSubsetSum(vector<int>nums, int target){
        // code here 
        int n = nums.size();
        cout<<target<<endl;
        if (target < 0) return false; //for negative 
        vector<bool> prev(target + 1, false);
        vector<bool> cur(target + 1, false);
        
        prev[0] = true;
        cur[0] = true;
        if (nums[0] <= target)
            prev[nums[0]] = true;
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                
                bool notTake = prev[ j];
                
                bool take = false;
                if (nums[i] <= j) {
                    take = prev[j - nums[i]];
                }
        
                cur[j] = take || notTake;
            }
            prev = cur;
        }
        
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) totalSum += nums[i];

        int target = totalSum / 2;
        if (totalSum % 2) // if odd return false
            return false;

        return isSubsetSum(nums, target);
    }
};