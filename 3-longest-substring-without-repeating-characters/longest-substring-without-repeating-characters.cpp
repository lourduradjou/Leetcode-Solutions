class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        int maxLength = 0;
        vector<int> charIndex(128,-1);
        int left = 0;

        for(int right = 0; right < n; right++) {
            if(charIndex[s[right]] >= left) {//if char already occured move the left pointer to the next of repeating character
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};