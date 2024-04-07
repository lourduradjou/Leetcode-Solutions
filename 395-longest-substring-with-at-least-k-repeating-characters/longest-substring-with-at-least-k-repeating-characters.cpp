class Solution {
public:
    int longestSubstring(string s, int k) {
        int right = 0, left = 0, maxLength = 0;
        int n = s.size();

        unordered_map<char,int> freqCounter;
        int cnt = 0;

        for (int limit = 1; limit <= 26; limit++) {
            freqCounter.clear();
            left = 0; right = 0; cnt = 0;
            
            while ( right < s.size() ) {
                freqCounter[s[right]]++;
                if ( freqCounter[s[right]] == k )
                    cnt++;
                //shrink the left side when crosses limit
                while ( freqCounter.size() > limit ) {
                    if ( freqCounter[s[left]] == k )
                        cnt--;
                    freqCounter[s[left]]--;

                    if ( freqCounter[s[left]] == 0 )
                        freqCounter.erase(s[left]);
                    left++;
                }

                if ( cnt == freqCounter.size() )
                    maxLength = max(maxLength, right - left + 1);
                right++;
            }
        }
        return maxLength;
    }
};