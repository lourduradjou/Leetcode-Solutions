class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int i = 0;
        int flag = 0;

        if (intervals.size() == 0)
        {
            return {{newStart, newEnd}};
        }
        
        for (; i < intervals.size(); ) {
            vector<int> interval = intervals[i];
            int start = interval[0];
            int end = interval[1];

            if ( end < newStart )
                ans.push_back({start, end});
            else if (newEnd < start) {
                flag = 1;
                ans.push_back({newStart, newEnd});
                break;
            }
            else {
                //start is the same so we need to find the merged one
                flag = 1;
                int lowStart = min(start, newStart);
                int highEnd = max(end, newEnd);
                
                i++;
                while (i < intervals.size() && intervals[i][0] <= highEnd) {
                    highEnd = max(highEnd, intervals[i][1]); 
                    i++;
                }
                
                ans.push_back({lowStart, highEnd});
                break;
            }

            i++;
        }
        while (i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }

        if (flag == 0) 
            ans.push_back({newStart, newEnd});
            
        return ans;
    }
};