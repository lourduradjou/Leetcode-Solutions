class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //using the given array to solve it
        int size = nums.size();

        for(int i  = 0; i < size; i++) {
            if(nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }

        vector<int> ans;
        for(int i = 0; i < size; i++) {
            if(nums[i] > 0)
                ans.push_back(i+1);
        }

        return ans;
    }
};