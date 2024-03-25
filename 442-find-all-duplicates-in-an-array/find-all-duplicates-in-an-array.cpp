class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;

        for (auto it: nums) {
            if (st.find(it) != st.end())
                ans.push_back(it);
            else
                st.insert(it);
        }

        return ans;
    }
};