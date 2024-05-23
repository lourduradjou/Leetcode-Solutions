class Solution {
    private:
        int findBeautifulSubsets(int index, int limit, vector<int>& nums, unordered_map<int, int>& mpp) {
            if (index == nums.size()) return 1;

            int taken = 0;
            if ( !mpp[nums[index] - limit] && !mpp[nums[index] + limit]) {
                mpp[nums[index]]++;
                taken = findBeautifulSubsets(index + 1, limit, nums, mpp);
                mpp[nums[index]]--;
            }

            //not taken count
            int notTaken = findBeautifulSubsets(index + 1, limit, nums, mpp);
            return taken + notTaken;
        }
    public:
        int beautifulSubsets(vector<int>& nums, int k) {
            unordered_map<int, int> mpp;
            int ans = findBeautifulSubsets(0, k, nums, mpp);
            return ans - 1; //removing the empty subset from the count
        }
};