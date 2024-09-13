class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans, prefixXor(arr.size() , 0);
        prefixXor[0] = arr[0];
        //prefix xor
        for (int i = 1; i < arr.size(); i++) {
            prefixXor[i] = prefixXor[i-1] ^ arr[i];
        }

        for (int i = 0; i < queries.size(); i++) {
            //firstly we will remove the front elements
            int x = queries[i][0];
            int y = queries[i][1];

            int value = prefixXor[y];
            for (int j = 0; j < x; j++) {
                value ^= arr[j];
            }

            ans.push_back(value);
        }

        return ans;
    }
};