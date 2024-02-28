class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> freqMap;
        for(auto ch: num)
            freqMap[ch]++;
        
        // for(auto it: freqMap) {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for (int i = 0; i < num.size(); i++) {
            int digitFreq = freqMap['0' + i];
            int occurance = num[i] - '0';
            // cout<<digitFreq<<" "<<occurance<<endl;

            if ( digitFreq != occurance )
                return false;
        }

        return true;

    }
};