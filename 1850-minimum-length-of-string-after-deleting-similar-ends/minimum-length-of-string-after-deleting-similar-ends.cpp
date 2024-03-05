class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int low = 0;
        int high = n - 1;

        while (low < high && s[low] == s[high]) {
            while (low < n && s[low] == s[high])
                low++;
            while (high >= 0 && s[low-1] == s[high])
                high--;
        }

        cout<<n<<endl;
        return (low > high) ? 0 : (high - low) + 1;
    }
};