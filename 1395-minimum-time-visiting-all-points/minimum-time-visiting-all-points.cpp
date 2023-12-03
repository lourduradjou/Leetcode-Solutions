class Solution {
public:

    int findDistance(const vector<int> &from,const vector<int> &to) 
    {
        int xDiff = abs(from[0] - to[0]);
        int yDiff = abs(from[1] - to[1]);

        return max(xDiff, yDiff);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;

        for(int i = 1; i < points.size(); i++) {
            totalTime += findDistance(points[i-1], points[i]);
        }

        return totalTime;
    }
};