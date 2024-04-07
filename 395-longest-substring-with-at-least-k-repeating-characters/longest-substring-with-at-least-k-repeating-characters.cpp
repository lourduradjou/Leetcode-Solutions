class Solution {
public:
    int longestSubstring(string s, int k) {
        int r = 0, l = 0, maxLength = 0;
        int n = s.size();

        unordered_map<char,int> mpp;
        int cnt = 0;

        for (int limit = 1; limit <= 26; limit++) {
            mpp.clear();
            l = 0;
            r = 0;
            cnt = 0;

            while (r < s.size()) {
                mpp[s[r]]++;
                if (mpp[s[r]] == k)
                    cnt++;
                //shrink the left side 
                while (mpp.size() > limit) {
                    if (mpp[s[l]] == k)
                        cnt--;
                    mpp[s[l]]--;

                    if (mpp[s[l]] == 0)
                        mpp.erase(s[l]);
                    l++;
                }
                if (cnt == mpp.size())
                    maxLength = max(maxLength, r - l + 1);
                r++;
            }
        }
        return maxLength;
    }
};