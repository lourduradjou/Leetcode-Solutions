class Solution {
public:
    int maxScore(vector<int>& nums) {
        //they are asking after making some prefix sum array give the number of positive
        ///numbers in it but that should be maximized that's all the question is

        //simple greedy approach is enough
        sort(nums.begin(), nums.end(), greater<int>());
        // if (nums[0] <= 0) return 0; //first element itsel is negative means nothing pos is possible

        long long ans = 0;
        int i = 0;

        for (i = 0; i < nums.size(); i++) {
            ans += nums[i];
            if (ans <= 0) break;
        }

        return i;
    }
};