class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        total = 0
        smallest_rem_one = float('inf')
        smallest_rem_two = float('inf')

        for num in nums:
            total += num

            if num % 3 == 1:
                smallest_rem_two = min(smallest_rem_two, smallest_rem_one + num)
                smallest_rem_one = min(smallest_rem_one, num)
            
            if num % 3 == 2:
                smallest_rem_one = min(smallest_rem_one, smallest_rem_two + num)
                smallest_rem_two = min(smallest_rem_two, num)

        
        if total % 3 == 0:
            return total
        if total % 3 == 1:
            return total - smallest_rem_one
        if total % 3 == 2:
            return total - smallest_rem_two