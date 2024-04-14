class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        maxSum = 0
        n = len(piles)

        print(piles)
        for i in range(n // 3, len(piles), 2):
            print(i)
            maxSum += piles[i]
        
        return maxSum