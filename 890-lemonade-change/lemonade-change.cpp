class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //greedy comes here as a part of giving the maximum change to the customer 
        //if possible like if 20 dollar if given it is best to give one 10 and 5 , instead 
        // of three 5 , of course the best case is checked first and then the worst case 
        //is checked further and further if not return false;

        int cntFive = 0, cntTens = 0;

        for (auto bill : bills) {
            if (bill == 5)
                cntFive++;
            else if (bill == 10) {
                if (cntFive > 0)
                {
                    cntFive--;
                    cntTens++;
                }
                else {
                    return false;
                }
            } 
            else {
                if (cntTens > 0 && cntFive > 0) {
                    cntTens--;
                    cntFive--;
                } 
                else if (cntFive >= 3)
                    cntFive -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};