class Solution:
    def findNthDigit(self, n: int) -> int:
        if n <= 9:
            return n
        
        base = 9
        digits = 1

        while n > (base * digits):
            n -= (base * digits)
            base *= 10
            digits += 1
        
        num = 10 ** (digits - 1) + (n - 1) // digits
        index = (n - 1) % digits

        return (int)(str(num)[index])