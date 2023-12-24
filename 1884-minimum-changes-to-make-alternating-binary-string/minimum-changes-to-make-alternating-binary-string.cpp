class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n == 1) return 0;

        int cnt_With_Starting_One = 0;
        int cnt_With_Starting_Zero = 0;

        for(int i = 0; i < n; i++) {
            if((i % 2 == 0) && s[i] != '0') cnt_With_Starting_Zero++;
            if((i % 2 == 1) && s[i] != '1') cnt_With_Starting_Zero++;
        }

        for(int i = 0; i < n; i++) {
            if((i % 2 == 0) && s[i] != '1') cnt_With_Starting_One++;
            if((i % 2 == 1) && s[i] != '0') cnt_With_Starting_One++;
        }

        return min(cnt_With_Starting_Zero, cnt_With_Starting_One);
    }
};