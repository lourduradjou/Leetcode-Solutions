class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxPiles = 0;
        sort(piles.begin() , piles.end());

        int left = 0;
        int right = piles.size() - 1;

        while(left <= right) {
            maxPiles += piles[right - 1];
            cout<<piles[right-1]<<endl;
            left++;
            right -= 2;
        }

        return maxPiles;
    }
};