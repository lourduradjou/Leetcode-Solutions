class Solution {
private:
    bool isSelfDividingNumber(int num) {
        int divident = num;

        while ( num > 0 ) {
            int divisor = num % 10;
            if (divisor == 0 || divident % divisor != 0) {
                return false;
            }
            num = num / 10;
        }

        return true;
    }
    
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i) )
                ans.push_back(i);
        }

        return ans;
    }
};