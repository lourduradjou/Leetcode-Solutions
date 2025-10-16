class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left = 1
        right = 1
        cnt = 1

        while right < len(nums):
            if nums[right - 1] != nums[right]: 
                #this is a unique number
                nums[left] = nums[right]
                left += 1
                cnt += 1
            
            right += 1
        

        return cnt
