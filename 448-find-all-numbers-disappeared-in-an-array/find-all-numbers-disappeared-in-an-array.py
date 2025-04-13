class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        #using set store the numbers which are there already
        #iterate and find the missing one
        set_nums = set(nums)
        missed_numbers = []

        for req_num in range(1, len(nums) + 1):
            if req_num not in set_nums:
                missed_numbers.append( req_num )
        
        return missed_numbers