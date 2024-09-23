class Solution {
public:
int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        //little bit of maths plus dp
        //s1 is greater than s2 , s1 - s2 = d, s1 = totSum - s2
        //totSum - s2 - s2 = d
        //therefore totSum - d / 2 is the required subset (S2) we wanna find
        
        int totSum = 0;
        for (auto it: arr) totSum += it;
        int sum = (totSum - d) / 2; //required subset
        
        //it has to be greater than zero and fractions are not allowed , so check if it is odd
        // if it is even then it is fine
        if ( (totSum - d) < 0 || (totSum - d) % 2 ) return 0;
        vector<int> prev(sum + 1, 0);
        
        //base cases
        if (arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if (arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int target = sum; target >= 0; target--) {
                int notPick = prev[target];
                int pick = 0;
                if (arr[ind] <= target) {
                    pick = prev[target - arr[ind]];
                }
                
                prev[target] = (pick + notPick);
            }
        }
        
        return prev[sum];
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //this problem is simply the modification of the partition with given difference
        return countPartitions(nums.size(), target, nums);
    }
};