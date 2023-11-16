class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //has table to solve this one
        int size = nums.size();
        vector<int> arr;
        arr.resize(size + 1, 0);

        for(int i  = 0; i < nums.size(); i++) {
            arr[nums[i]] = 1;
        }

        vector<int> ans;
        for(int i = 1; i <= nums.size(); i++) {
            if(arr[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};