class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //using recursion + memoization 
        int n = prices.size();
        // vector<int> next(2, 0);
        // vector<int> cur(2, 0);
        int nextNotTake,nextTake,curNotTake,curTake;
        nextTake = nextNotTake = 0; //base case , yeah in the tabu itself write that , to understand easily here
        
        for (int ind = n-1; ind >= 0; ind--) {
            curTake = max( 
                        (-prices[ind] + nextNotTake), //bought the stock
                        (0 +  nextTake) // not bought the stock
            );
            curNotTake = max( 
                        (prices[ind] + nextTake), //sold the stock
                        (0 +  nextNotTake) // not sold the stock
            );
            nextTake = curTake;
            nextNotTake = curNotTake;
        }

        return nextTake; 
    }
};