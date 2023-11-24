class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //find the max one and also the freq of the elements
        int maxi = *max_element(piles.begin(), piles.end());
        int n = piles.size();
        vector<int> freq(maxi + 1, 0);

        for(int i = 0; i < n; i++) {
            freq[piles[i]]++;
        }  

        int maxCoins = 0;
        int chance = n / 3;
        bool turn = true;

        while(chance) {
            if(freq[maxi] > 0) {
                if(turn) turn = false;
                else {
                    chance--;
                    turn = true;
                    maxCoins += maxi;
                }
                freq[maxi]--;
            }
            else {
                maxi--;
            }
        }

        return maxCoins;
    }
};