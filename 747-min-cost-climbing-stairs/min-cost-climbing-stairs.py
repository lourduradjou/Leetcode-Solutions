class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        memo = {}

        def dfs(i):
            if i >= n:
                return 0
            
            if i in memo:
                return memo[i]

            memo[i] = cost[i] + min(dfs(i+1), dfs(i+2))
            return memo[i]
        
        return min(dfs(0), dfs(1))