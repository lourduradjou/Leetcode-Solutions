class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        //count the frequency and iterate from the back and
        //count the operations required

        int n = nums.size();
        vector<int> freq(50001, 0);

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        int res = 0, operations = 0;
        for(int i = 50000; i >= 1; i--) {
            if( freq[i] > 0 ) {
                operations += freq[i];
                res += (operations - freq[i]);
            }
        }

        return res;
    }
};