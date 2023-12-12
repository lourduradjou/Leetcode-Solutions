class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)
            return 1;
        
        vector<int> trustCount(n + 1);

        for(auto &person: trust) {
            trustCount[person[0]]--;
            trustCount[person[1]]++;
        }

        for(int person = 0; person < trustCount.size(); person++) {
            if( trustCount[person] == n - 1 ) //only if he is trusted by n - 1 peoples he is the judge
            return person;
        }

        return -1;
    }
};