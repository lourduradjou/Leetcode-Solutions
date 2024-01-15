class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        details = {}

        for match in matches:
            details.setdefault(match[0], 0)
            details[match[1]] = details.get(match[1], 0) - 1

        vec1 = []
        vec2 = []

        for key, value in details.items():
            if value == 0:
                vec1.append(key)
            elif value == -1:
                vec2.append(key)
        
        return [sorted(vec1), sorted(vec2)]
            