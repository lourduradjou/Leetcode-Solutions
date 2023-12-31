class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        //just store the character and its index in a map and use it when it occurs again
        //make sure to store the first appearing index so that we can get the maximum answer
        unordered_map<char,int> mpp;
        int maxLength = -1;

        if(s.size() == 2) return 0;
        if(s.size() < 2) return maxLength;

        for(int i = 0; i < s.size(); i++) {
            if(mpp.find(s[i]) == mpp.end())// it is not there 
            {
                mpp[s[i]] = i;
            }
            else // if it is there means update the ans value and go 
            {
                int count = i - mpp[s[i]] - 1;
                maxLength = max(maxLength, count);
            }
        }

        return maxLength; 
    }
};