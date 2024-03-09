class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        //using a simple low and high range binary search can do the job
        //bit tricky to get this idea ha ha
        const int MOD = 1e9+7;
        //lower end or starting possible value
        long long low = min(a, b);
        //higher possible number
        long long high = low * (long long)n;

        long long lcm = (a * b) / __gcd(a, b);
        long long mid, possibleCounts;
        // while (b != 0) {
        //     temp = b;
        //     b = a % b;
        //     a = temp;
        // } gcd stuffs usign euclidead algo better we can use inbuilt if there
        while ( low < high ) {
            mid = low + (high - low) / 2;
            possibleCounts = (mid / a + mid / b - mid / lcm);

            if (possibleCounts < n)
                low = mid + 1;
            else
                high = mid;
        }

        return (low) % MOD;
    }
};