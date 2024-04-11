class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        //this is kinda maximization (greedy) problems we have to maximize the count of
        //filled bags which contains full of rocks before or after addition of rocks in it
        //

        //so we need to find the remaining rocks to be filled from the given values
        int n = rocks.size();
        vector<int> rocksRequired(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            rocksRequired[i] = (capacity[i] - rocks[i]);
        }
        sort(rocksRequired.begin(), rocksRequired.end());

        for (int i = 0; i < n; i++) {
            if (rocksRequired[i] <= additionalRocks) {
                additionalRocks -= rocksRequired[i];
                ans++;
            }
        }

        return ans;
    }
};