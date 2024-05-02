class Solution {
public:
    int jump(vector<int>& nums) {
        int reachableDistance = 0, count = 0, lastIndex = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            reachableDistance = max(reachableDistance, i + nums[i]);

            if ( i == lastIndex ) {
                lastIndex = reachableDistance;
                count++;
            }
        }

        return count;
    }
};