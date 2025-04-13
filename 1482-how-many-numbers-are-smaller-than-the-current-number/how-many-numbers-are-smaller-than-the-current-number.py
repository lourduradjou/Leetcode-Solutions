class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        # Good solution is to sort the values and see how many
        # numbers are before than that, but we also need to get that sorted number indexes -> hashmap would help us
        sorted_nums = sorted(nums)
        value_to_index = {}
        result = []

        for index, value in enumerate(sorted_nums):
            if value not in value_to_index:
                value_to_index[value] = index
        
        for num in nums:
            count_lesser = value_to_index[num]
            result.append(count_lesser)
        
        return result