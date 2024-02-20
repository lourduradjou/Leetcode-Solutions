class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //binary search approach
        //sort the array first
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;

        while( low <= high ) {
            int mid = low + (high - low) / 2;

            if( nums[mid] == mid )
                low = mid + 1;
            else 
                high = mid - 1;
        }

        return low;
    }
};