class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = 0
        while i < n:
            nums1[m + i] = nums2[i]
            i += 1
        
        return nums1.sort()