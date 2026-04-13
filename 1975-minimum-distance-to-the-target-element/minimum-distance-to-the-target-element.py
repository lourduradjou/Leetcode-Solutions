class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        minAns = float('inf')

        for i in range(len(nums)):
            if nums[i] == target:
                minAns = min(minAns, abs(i - start))

        return minAns