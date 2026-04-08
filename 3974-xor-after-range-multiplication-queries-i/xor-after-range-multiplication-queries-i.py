class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for query in queries:
            idx = query[0]
            rightIdx = query[1]
            k = query[2]
            mulV = query[3]

            while idx <= rightIdx:
                nums[idx] = (nums[idx] * mulV) % (10**9 + 7)
                idx += k
            
        xorRes = nums[0]

        for i in range(1, len(nums)):
            xorRes ^= nums[i]
        
        return xorRes