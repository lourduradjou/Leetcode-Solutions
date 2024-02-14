class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0;
        int negIndex = 1;
        vector<int> ans(nums.size());

        for(int i=0; i<nums.size(); i++)
        { 
            if(nums[i] < 0) 
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{ 
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};