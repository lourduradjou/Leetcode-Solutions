class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9)
            return n;
        
        long long base = 9;
        long long digits = 1;

        while ((long long)n > (base * digits)) {
            n -= (base * digits);
            base *= 10;
            digits += 1;
        }
        long long num = pow(10, (digits - 1)) + (n - 1) / digits;
        long long index = (n - 1) % digits;

        return to_string(num)[index] - '0';
    }
};