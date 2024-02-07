class Solution {
public:
    string frequencySort(string s) {
        //using bucket sort we can achieve O(N) tc so lets try that
        unordered_map<char, int> freq;
        for(auto ch: s) freq[ch]++;

        int n = s.size();
        vector<vector<char>> bucket(n+1);
        for(auto [ch, fq]: freq) bucket[fq].push_back(ch);

        string ans = "";
        for(int i = n; i >= 1; i--) {
            for(auto ch: bucket[i]) {
                ans.append(i, ch);
            }
        }
        return ans;
    }
};