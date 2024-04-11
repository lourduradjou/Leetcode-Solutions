class Solution {
public:
    int findContentChildren(vector<int>& reqCookies, vector<int>& availableCookies) {
        //it is kinda greedy approach to maximize optimization problems
        //sort the reqCookies array from min to max so that we can satisfy maximum children

        sort(reqCookies.begin(), reqCookies.end());
        sort(availableCookies.begin(), availableCookies.end());
        int satisfiedCounts = 0;

        int i = 0, j = 0;
        int n = reqCookies.size(), m = availableCookies.size();

        while (i < n && j < m) {
            if ( reqCookies[i] <= availableCookies[j] )
            {
                i++;
                j++;
                satisfiedCounts++;
            }
            else 
                j++;
        }

        return satisfiedCounts;
    }
};