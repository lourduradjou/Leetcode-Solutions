class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        bool timeON[2001] = {};

        //Sorting on the basis on end time to align the tasks parallely
        sort(tasks.begin(), tasks.end(), [](const auto &t1, const auto &t2) {
            return t1[1] < t2[1];
        });

        for (auto &task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            //just take the spread the things from the task array
            for (int i = start; i <= end; i++) 
                if (timeON[i]) duration--;
            //the above portion tries to fill the tasks if alreay same tasks running
            //on that spot
            for (int i = end; duration > 0; i--) {
                if (timeON[i]) continue;
                duration--;
                timeON[i] = true;
            }
            //the above block tries to put the remaining tasks at the end 
            //so that the next tasks could parallely run with the tasks..
        }

        int countMachineON = 0;
        for (int i = 1; i <= 2000; i++) countMachineON += timeON[i];

        return countMachineON;
    }
};