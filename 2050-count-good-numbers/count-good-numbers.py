class Solution:
    def countGoodNumbers(self, n: int) -> int:
        # using simple combinatorics idea we can solve this pattern
        # even indices gonna have atmost 5 values (0,2,4,6,8)
        # Note: 0 is not allowed in the first place
        # odd  indices gonna have atmost 4 values (2,3,5,7)

        MOD = 10**9 + 7
        even_count = (n + 1) // 2
        odd_count  = n // 2

        odd_number_variations = pow(4, odd_count, MOD)
        even_number_variations = pow(5, even_count, MOD)

        total_variations = (odd_number_variations * even_number_variations) % MOD

        return total_variations 