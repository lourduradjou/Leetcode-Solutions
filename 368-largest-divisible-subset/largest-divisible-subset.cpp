class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> lisLength(n, 1), prevIndex(n, -1);
        int maxLen = 0, index = -1;

        sort(nums.begin(), nums.end()); //sorting to decreasing the checking requirements ..without that also we can do
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && 1 + lisLength[j] > lisLength[i]) {
                    lisLength[i] = 1 + lisLength[j];
                    prevIndex[i] = j;
                }
            }

            //for the i th value we can found the best possible subset
            if(lisLength[i] > maxLen) {
                maxLen = lisLength[i];
                index = i;
            }
        }

        vector<int> ans;
        while(index != -1) {
            ans.push_back(nums[index]);
            index = prevIndex[index];
        }

        return ans;

    }
};