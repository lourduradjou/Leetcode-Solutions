#include <algorithm>

class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int, int>> visitedArray;
        map<char, pair<int, int>> dir = {
            {'N', {0, 1}}, 
            {'S', {0, -1}}, 
            {'E', {1, 0}}, 
            {'W', {-1, 0}}
        };

        int currX = 0;
        int currY = 0;
        visitedArray.push_back({0,0});
        
        for (char ch : path) {
            currX += dir[ch].first;
            currY += dir[ch].second;

            if (find(visitedArray.begin(), visitedArray.end(), 
            make_pair(currX, currY)) != visitedArray.end()) {
                cout<<currX<<" "<<currY;
                return true; 
            } else {
                cout<<currX<<" "<<currY<<endl;
                visitedArray.push_back({currX, currY});
            }
        }

        return false;
    }
};
