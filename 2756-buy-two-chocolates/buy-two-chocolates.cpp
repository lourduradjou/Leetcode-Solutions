class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //find the two minimum , add them and subtract with the money
        //you have if not negative return the leftover else return the money 
        //sort(prices.begin(), prices.end());

        int firstMin = min(prices[0], prices[1]);
        int secondMin = max(prices[0], prices[1]);

        for(int i = 2; i < prices.size(); i++) {
            if(prices[i] < firstMin) {
                secondMin = firstMin;
                firstMin = prices[i];
            }
            else if(prices[i] < secondMin) {
                secondMin = prices[i];
            }
        }

        int leftOverMoney = money - (firstMin + secondMin);
        return leftOverMoney < 0 ? money : leftOverMoney;
    }
};