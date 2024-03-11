class Solution:
    def customSortString(self, order: str, s: str) -> str:
        ans = ""
        freq_map = {}

        for char in s:
            if char in freq_map:
                freq_map[char] += 1
            else:
                freq_map[char] = 1
        
        for i in order:
            if i in s:
                ans += (i * freq_map[i])
            
        for i in s:
            if i not in ans:
                ans += (i * freq_map[i])
        
        return ans