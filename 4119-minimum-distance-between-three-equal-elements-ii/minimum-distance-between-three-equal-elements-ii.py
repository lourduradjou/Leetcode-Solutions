class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)

        mp = defaultdict(list)
        result = float('inf')

        for k in range(len(nums)):
            mp[nums[k]].append(k)

            if len(mp[nums[k]]) >= 3:
                i = mp[nums[k]][-3]
                result = min(result, 2*(k-i))
        
        return result if result != float('inf') else -1