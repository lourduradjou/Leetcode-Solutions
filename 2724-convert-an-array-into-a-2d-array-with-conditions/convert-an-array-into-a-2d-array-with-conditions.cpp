class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it: nums)
            mpp[it]++;
        
        vector<vector<int>> ans;
        int size = nums.size();

        while(size > 0) {
            vector<int> temp;
            for (auto it: mpp) {
                if (it.second != 0) {
                    temp.push_back(it.first);
                    mpp[it.first]--;   
                    size--;       
                }         
            }
            ans.push_back(temp);
        }
        return ans;
  
    }
};