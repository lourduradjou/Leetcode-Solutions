class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        #prefix sum and hashmap 
        #running sum and hashmap is used to reduce the tc from n^2 to n
        #brute force is just to generate and apply the condition would give tle n^2
        #prefix should come to the mind whenever there is subarray sum and certain conditions with it

        cnt = 0
        prefixSum = 0
        map = {
            0 : 1
        }

        for num in nums:
            prefixSum += num
            mod = prefixSum % k
            #if mod goes down zero add k to get it as positive
            if (mod < 0):
                mod += k
            if (mod in map):
                cnt += map[mod]
                map[mod] += 1
            else:
                map[mod] = 1
        
        return cnt
