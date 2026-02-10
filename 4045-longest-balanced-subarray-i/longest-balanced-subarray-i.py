class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        highestLength = 0
        for i in range(len(nums)):
            neven = set()
            nodd = set()
            for j in range(i, len(nums)):
                if nums[j] % 2 == 0:
                    neven.add(nums[j])
                else:
                    nodd.add(nums[j])
                
                if len(neven) == len(nodd):
                    highestLength = max(highestLength, j - i + 1)
        

        return highestLength
    