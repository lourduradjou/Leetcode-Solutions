class Solution {
private:
    int findDigits_Div_Count(int num) {
        int divident = num;
        int count = 0;

        while ( num > 0 ) {
            int divisor = num % 10;
            if (divisor != 0 && divident % divisor == 0) {
                count++;
            }
            num = num / 10;   
        }

        return count;
    }

public:
    int countDigits(int num) {
       return findDigits_Div_Count(num);
    }
};