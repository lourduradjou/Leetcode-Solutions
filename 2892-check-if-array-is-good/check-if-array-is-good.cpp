class Solution {
public:
    bool isGood(vector<int>& nums) {
        //solution is very simple just think about the structure
        //last two will be same and all other will be 1 to n 
        //if this structure is there return true
        //else retur false

        int n = nums.size();
        if(n <= 1)
            return false; // there should be atleast two elements
        
        sort(nums.begin(), nums.end());
        
        if(nums[n - 2] != nums[n -1])
            return false;
        
        for(int i = 0; i < n-1; i++) {
            if(nums[i] != i+1)
                return false;
        }

        return true;
    }
};