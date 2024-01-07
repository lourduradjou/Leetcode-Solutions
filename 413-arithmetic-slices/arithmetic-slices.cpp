class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(); int ans=0;
        if(n<3){return 0;}

        int prev_dp=0; int cur_dp=0;
        for(int i=2;i<n;++i){
            cur_dp=0;
            if((nums[i]-nums[i-1])==(nums[i-1]-nums[i-2])){cur_dp=1+prev_dp;}
            prev_dp=cur_dp;
            ans+=cur_dp;
        }
        return ans;
    }
};