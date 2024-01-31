class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brute force is
        int n = temperatures.size(); 
        vector<int> ans(n, 0);
        //a tricky algo to solve this problem using constact space
        int maxHottest = -1;

        for(int i = n - 1; i >= 0; i--) {
            if(temperatures[i] >= maxHottest) {
                maxHottest = temperatures[i];
                continue;
            }

            int days = 1;
            while(temperatures[i + days] <= temperatures[i]) {
                days += ans[i + days];
            }

            ans[i] = days;
        }

        return ans;
    }
};