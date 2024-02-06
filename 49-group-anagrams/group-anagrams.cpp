class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(auto str: strs) {
            string storeStr = str;
            sort(str.begin(), str.end());

            mpp[str].push_back(storeStr);        
        }

        vector<vector<string>> ans;
        for(auto it: mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};