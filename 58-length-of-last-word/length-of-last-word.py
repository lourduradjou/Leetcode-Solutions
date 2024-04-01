class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        eachWordCount = []
        cnt = 0

        for i in range(0, len(s)):
            if i is not " ":
                start = i
                break
    
        for i in range(start, len(s)):
            if s[i] is " ":
                if cnt != 0:
                    eachWordCount.append(cnt)
                    cnt = 0
            else:
                cnt += 1
        
        if cnt != 0:
            eachWordCount.append(cnt)

        print(eachWordCount)
        return eachWordCount[-1]