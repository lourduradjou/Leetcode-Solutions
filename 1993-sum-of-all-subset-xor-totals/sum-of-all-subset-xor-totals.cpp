class Solution {
private:
    int findSubsetSum(vector<int> &nums, int index, int currXor) {
        if (index == nums.size())
            return currXor;
        
        //pick
        int pickValue = findSubsetSum(nums, index + 1, currXor ^ nums[index]);
        //not pick
        int notPickValue = findSubsetSum(nums, index + 1, currXor);
        return pickValue + notPickValue;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        //using recursion pick and not pick method
        return findSubsetSum(nums, 0, 0);
    }
};