class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrowsUsed = 1;
        int endRange = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > endRange) //crossed the range so take the new end
            {
                arrowsUsed++;
                endRange = points[i][1];
                cout<<endRange<<endl;
            }
        }

        // for (auto it: points) {
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        return arrowsUsed;
    }
};