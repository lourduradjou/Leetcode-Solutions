class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        #find the total num of the required array and subtract it witht the current sum to get the missing answer -> O(1) solution
        requiredSum = sum(range( len(nums) + 1 ))
        actualSum = sum(nums)

        return requiredSum - actualSum