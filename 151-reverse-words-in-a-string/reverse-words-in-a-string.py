class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        words.reverse()
        reversedWordString = " ".join(words)
        return reversedWordString