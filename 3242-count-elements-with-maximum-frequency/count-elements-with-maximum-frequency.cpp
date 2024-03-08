class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto it: nums) {
            mpp[it]++;
        }

        int maximum_freq;
        for (auto it: mpp) 
        {
            maximum_freq = max( maximum_freq, it.second);
        }

        int maximum_freq_count = 0;
        for (auto it: mpp) {
            if (it.second == maximum_freq)
                maximum_freq_count += maximum_freq;
        }

        return maximum_freq_count;
    }
};