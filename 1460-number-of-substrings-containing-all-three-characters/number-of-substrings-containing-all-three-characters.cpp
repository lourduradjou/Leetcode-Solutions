class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> index = {-1, -1, -1};
        int substringCnt = 0;

        for (int i = 0; i < s.size(); i++) {
            index[s[i] - 'a'] = i;

            if (index[0] != -1 && index[1] != -1 && index[2] != -1)
                substringCnt += (1 + min({index[0], index[1], index[2]}) );
        }

        return substringCnt;
    }
};