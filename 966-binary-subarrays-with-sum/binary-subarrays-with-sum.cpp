class Solution {
private:
    int findSubArrayCounts(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        
        int l = 0, r = 0;
        int n = nums.size();
        int maxCount = 0;
        long long sum = 0;

        while (r < n) {
            sum += nums[r];

            while (sum > goal && l < n) {
                sum = sum - nums[l];
                l++;
            }

            maxCount += (r - l + 1);
            r++;
        }

        return maxCount;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //this is model like <= k and <=  k-1 kinda stuffs...so subtraction of both the stuffs 
        //will give the required answer
        return findSubArrayCounts(nums,goal) - findSubArrayCounts(nums, goal - 1);
    }
};