class Solution {
public:
    int numSquares(int n) {
        //using legendre's three sqaure sum formula this could be easily solved
        //at max we can represent a number by 4 number of sqaure sums
        //and legendre's says if the equation 4^k(8m + 7) == 0 then only four times is the only possible and shortest way
        //to represent in sqaures sum way
        int squareNum = (int)sqrt(n);
        if(squareNum * squareNum == n) return 1;

        while(n % 4 == 0) // (4^k) * (8m + 7)
            n /= 4;     
        if(n % 8 == 7) return 4;

        //here n is modified but will still work, because even if it is modified you are still finding the answer for that
        //modified one only, and also it it only divided by 4 if it is divisible by four.
        for(int i = 1; i * i <= n; i++) {
            int squareA = i * i;
            int possibleNum = (int) sqrt(n - squareA);

            if(possibleNum * possibleNum == n - squareA)
                return 2;
        }

        return 3;

    }
};