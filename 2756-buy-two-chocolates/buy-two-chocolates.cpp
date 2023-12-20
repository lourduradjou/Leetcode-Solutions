class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //find the two minimum , add them and subtract with the money
        //you have if not negative return the leftover else return the money 
        sort(prices.begin(), prices.end());

        int firstMin = prices[0];
        int secondMin = prices[1];

        int leftOverMoney = money - (firstMin + secondMin);

        if(leftOverMoney < 0) 
            return money;
        else
            return leftOverMoney;

        // for(int i = 1; i < prices.size(); i++) {
        //     if(prices[i] <= firstMin) {
        //         secondMin = firstMin;
        //         firstMin = prices[i];
        //     }
        // }
    }
};