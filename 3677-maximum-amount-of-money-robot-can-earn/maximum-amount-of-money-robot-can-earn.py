class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        self.n = len(coins)
        self.m = len(coins[0])
        self.NEG = float('-inf')
        self.dp = [[[None] * 3 for _ in range(self.m)] for _ in range(self.n)]

        return self._solve(0, 0, 2, coins)
    
    def _solve(self, i : int, j : int, k : int, coins : list[list[int]]) -> int:
        
        if i >= self.n or j >= self.m:
            return self.NEG

        if self.dp[i][j][k] is not None:
            return self.dp[i][j][k]

        #base case
        if i == self.n-1 and j == self.m-1:
            coin = coins[i][j]

            if coin >= 0:
                res = coin
            else: 
                res = 0 if k > 0 else coin
            
            self.dp[i][j][k] = res
            return res

        coin = coins[i][j]

        right = self._solve(i, j+1, k, coins)
        down = self._solve(i+1, j, k, coins)
        best = max(right , down)

        if coin >= 0:
            res = best + coin
        else:
            pay = coin + best
            skip = self.NEG

            if k > 0:
                skip = max (
                    self._solve(i, j+1, k-1, coins),
                    self._solve(i+1, j, k-1, coins)
                )
            
            res = max(pay, skip)
        
        self.dp[i][j][k] = res
        return res

