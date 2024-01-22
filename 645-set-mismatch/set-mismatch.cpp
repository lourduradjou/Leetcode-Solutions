class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> arr(nums.size() + 1, 0);

        for(int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        int missingNumber;
        int repeatedNumber;

        for(int i = 1; i <= nums.size(); i++) {
            if(arr[i] == 0)
                missingNumber = i;
            if(arr[i] == 2)
                repeatedNumber = i;
        }

        return {repeatedNumber, missingNumber};
    }
};