class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>v[v.size()-1]){
                v.push_back(nums[i]);
            }
            else {
                int lb = lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                // cout<<"index is "<<lb<<" "<<"ele: "<<nums[i]<<endl;
                // for(auto it: v) cout<<it<<" ";
                // cout<<endl;
                v[lb]=nums[i];
            }
        }
        return v.size();
    }
};