class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int flag = 1;
        for(int i = 31; i >= 0; i--) {
            if((1 << i) & n) {
                if(flag) {
                    ans += ((1 << (i+1)) - 1);
                    flag = 0;
                }
                else {
                    ans -= ((1 << (i+1)) - 1);
                    flag = 1;
                }
            }
        }

        return ans;
    }
};