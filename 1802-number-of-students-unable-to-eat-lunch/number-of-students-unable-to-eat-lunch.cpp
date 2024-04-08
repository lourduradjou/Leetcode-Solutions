class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentsQueue;
        for (auto student: students) {
            studentsQueue.push(student);
        }

        //now queue is ready lets iterate
        int i = 0;
        int cnt = 0;

        while (i < sandwiches.size()) {
            int currStudent = studentsQueue.front();
            if (sandwiches[i] == currStudent){
                cnt = 0;
                i++; //move to the next sandwich
                studentsQueue.pop(); //that student is served
            }else {
                //make the students go to the last place in the row
                //first take him from the row
                cnt++;
                studentsQueue.pop();
                studentsQueue.push(currStudent);
            }
            if (cnt == studentsQueue.size())
                return cnt;
        }

        return 0;
    }
};



//  cnt = 3
// students = [1,1,1], sandwiches = 0,1,1]






















