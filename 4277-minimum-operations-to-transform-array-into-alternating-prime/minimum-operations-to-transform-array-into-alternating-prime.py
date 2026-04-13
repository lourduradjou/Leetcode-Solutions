class Solution:
    def sieve(self, n):
        end = int(n**0.5 + 1)
        prime = [1] * (n+1)
        prime[0] = prime[1] = 0
        
        for i in range(2, end):
            if prime[i]:
                for j in range(i*i, n+1, i):
                    prime[j] = False

        return prime
            
    def minOperations(self, nums: list[int]) -> int:
        primes = self.sieve(10**5 + 4)
        reqAdd = 0

        for i in range(len(nums)):
            val = nums[i]
            if i % 2 == 0:
                while not primes[val]:
                    val += 1
                    reqAdd += 1
            else:
                while primes[val]:
                    val += 1
                    reqAdd += 1

        return reqAdd
        
        