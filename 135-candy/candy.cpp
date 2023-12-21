class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> candies(size, 1);

        for(int i = 1; i < size; i++) {
            //check the current with the left;
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }

        for(int i = size - 2; i >= 0; i--) {
            //check the current with the right 
            //if it is already greater leave it
            //or add one more candy then its neighbour
            if( ratings[i] > ratings[i+1] )
                candies[i] = max(candies[i], candies[i+1] + 1);
        }

        int result = accumulate(candies.begin(), candies.end(), 0);

        return result;
    }
};