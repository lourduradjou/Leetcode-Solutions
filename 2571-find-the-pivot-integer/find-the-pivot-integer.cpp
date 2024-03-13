class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;

        int currSum = 0;

        for (int i = 1; i <= n; i++) {
            currSum += i;
            //cout<<currSum<<" "<<totalSum - currSum<<endl;
            if (currSum == (totalSum - currSum + i))
                return i;
        }

        return -1;
    }
};