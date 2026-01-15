class Solution:
    def longestPalindrome(self, s: str) -> str:
        resStr = ""
        resLen = 0

        for i in range(len(s)):
            #for the odd length palindrome
            left, right = i, i
            while left >= 0 and right < len(s) and s[left] == s[right]:
                if (right - left + 1) > resLen:
                    resStr = s[left: right + 1]
                    resLen = right - left + 1
                left -= 1
                right += 1
            #for the even length palindrome
            left, right = i, i+1
            while left >= 0 and right < len(s) and s[left] == s[right]:
                if (right - left + 1) > resLen:
                    resStr = s[left: right + 1]
                    resLen = right - left + 1
                left -= 1
                right += 1

        return resStr