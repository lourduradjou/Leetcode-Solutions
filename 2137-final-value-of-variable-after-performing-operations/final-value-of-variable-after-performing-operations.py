class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        count = {
            '--X' : -1,
            'X--' : -1,
            '++X' : 1,
            'X++' : 1,
        }

        ans = 0

        for op in operations:
            ans += count[op]
        
        return ans