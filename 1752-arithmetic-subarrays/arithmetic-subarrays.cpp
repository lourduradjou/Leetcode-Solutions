class Solution {
public:

    bool checkForArithmeticProgression(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];

        for(int i = 2; i < arr.size(); i++) {
            int nextDiff = arr[i] - arr[i-1];
            if(diff != nextDiff) 
                return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;

        for(int i = 0; i < l.size(); i++) {
            vector<int> arr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.push_back(checkForArithmeticProgression(arr));
        }

        return ans;

    }
};