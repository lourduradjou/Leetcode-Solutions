class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 1 <= g.length <= 3 * 10^4
        // 0 <= s.length <= 3 * 10^4
        // 1 <= g[i], s[j] <= 2^31 - 1

        int maxContentChildren = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0;
        int right = 0;

        while(left < g.size() && right < s.size()) {
            if(g[left] <= s[right]) {
                maxContentChildren++;
                left++;
                right++;
            }
            else {
                right++;
            }
        }

        return maxContentChildren;
    }
};