from collections import Counter

class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        # To make the hashmap with frequency of the values reminders
        hash_map = Counter(num % value for num in nums)
        mex = 0

        while hash_map[mex % value] > 0:
            hash_map[mex % value] -= 1
            mex += 1
        
        return mex