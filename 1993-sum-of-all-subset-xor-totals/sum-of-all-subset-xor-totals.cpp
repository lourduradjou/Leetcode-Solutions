class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        //generate the subset
        //find the xor and keep adding , finally return 
        int sumOfSubset = 0;
        int n = nums.size();

        for (int i = 0; i < (1 << n); i++) {
            int currSum = 0;
            for (int j = 0; j < n; j++) {

                if (i & (1 << j))
                    currSum = currSum ^ nums[j];
            }    
            sumOfSubset += currSum;
        }

        //cout<<"Zero xor operation: "<<(0 ^ 8)<<endl;
        return sumOfSubset;
    }
};