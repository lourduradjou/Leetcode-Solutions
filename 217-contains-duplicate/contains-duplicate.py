class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        copyList = nums
       
        if len(set(copyList)) != len(nums):
            return True
            
        return False