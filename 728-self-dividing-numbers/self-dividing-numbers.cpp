class Solution {
private:
    bool isSelfDividingNumber(int num) {
        int divident = num;

        string divisorString = to_string(num);
        reverse(divisorString.begin(), divisorString.end());

        for(auto divChar: divisorString) {
            int divisor = stoi(string(1,divChar));
            if (divisor == 0) return false;
            if ( divident % divisor != 0 )
                return false;
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