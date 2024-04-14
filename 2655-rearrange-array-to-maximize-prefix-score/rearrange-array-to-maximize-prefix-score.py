class Solution:
    def maxScore(self, nums: List[int]) -> int:
        #simple greedy approach
        nums.sort(reverse = True)
        sumOfNumbers = 0
        
        for index , num in enumerate(nums):
            sumOfNumbers += num
            if sumOfNumbers <= 0:
                return index
            
        return len(nums)
        