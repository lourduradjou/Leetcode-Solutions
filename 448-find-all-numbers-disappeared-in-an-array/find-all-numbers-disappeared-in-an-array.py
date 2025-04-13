class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # By chaning the respective index values to be negative we
        # can easily iterate and see which index was never touch. 
        # space complexity of -> O(1) expect returning list

        missed_numbers = []

        for num in nums:
            index = abs(num) - 1
            nums[index] = -abs(nums[index])      
        
        for index in range(0, len(nums)):
            if nums[index] > 0: 
                missed_number = index + 1
                missed_numbers.append(missed_number)

        return missed_numbers