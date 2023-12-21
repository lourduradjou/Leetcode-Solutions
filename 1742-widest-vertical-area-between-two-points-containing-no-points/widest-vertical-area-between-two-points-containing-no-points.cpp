class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int maxWidestArea = 0;
        sort(points.begin(), points.end());
        int size = points.size();

        for( int i = 1; i < size; i++) {
            maxWidestArea = max( maxWidestArea, points[i][0] - points[i-1][0] );
        }

        return maxWidestArea;
    }
};