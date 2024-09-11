class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorNum = start ^ goal;
        int cnt = 0;

        while (xorNum) {
            if (xorNum & 1) 
                cnt++;
            xorNum = xorNum >> 1;
        }

        return cnt;

    }
};