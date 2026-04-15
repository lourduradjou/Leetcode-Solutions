class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        for i in range((n // 2) + 1):
            if words[(startIndex + i) % n] == target or words[(startIndex - i) % n] == target:
                return i
        
        return -1