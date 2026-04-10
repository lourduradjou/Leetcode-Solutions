class Solution:
    def minimumDistance(self, nums: List[int]) -> int:

        minDis = float('inf')
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1, len(nums)):
                    if nums[i] == nums[j] == nums[k]:
                        val = abs(i - j) + abs(j - k) + abs(k - i)
                        minDis = min(minDis, val)
        
        return minDis if minDis != float('inf') else -1
