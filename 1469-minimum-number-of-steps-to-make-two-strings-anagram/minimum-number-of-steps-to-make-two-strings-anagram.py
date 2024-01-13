class Solution:
    def minSteps(self, s: str, t: str) -> int:
        countS = [0] * 26
        countT = [0] * 26

        for char in  s:
            countS[ord(char) - ord('a')] += 1
        for char in t:
            countT[ord(char) - ord('a')] += 1
        
        steps = 0
        for i in range(26):
            steps += abs(countS[i] - countT[i])
        
        return steps // 2