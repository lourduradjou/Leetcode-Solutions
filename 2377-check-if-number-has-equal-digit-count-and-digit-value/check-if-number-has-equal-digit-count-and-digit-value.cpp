class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> freqMap;
        for(auto ch: num)
            freqMap[ch - '0']++;
        
        for (int i = 0; i < num.size(); i++) {
            if (freqMap[i] != num[i] - '0')
                return false;
        }

        return true;
    }
};