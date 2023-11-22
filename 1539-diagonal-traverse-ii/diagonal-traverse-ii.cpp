class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> storageVec;
        int length = nums.size();

        for(int i = 0; i < length; i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                storageVec.push_back( {i+j, length - i, nums[i][j]} );
            }
        }

        sort(storageVec.begin(), storageVec.end(), [](auto& a, auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });

        vector<int> ans;
        
        for(auto& it: storageVec) {
            ans.push_back(it[2]);
        }

        return ans;

    }


};