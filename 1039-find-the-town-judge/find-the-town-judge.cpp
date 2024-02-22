class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //if a person trust another person lets consider there
        //is a edge from A to B ...
        //though is to play with indegree and outdegree 
        //the town judge wouldn't believe anyone so outdegree will be 0
        //and all the ones will believe him so indegree will be n-1
        vector<int> inDegree(n + 1) , outDegree(n + 1);
        for (auto edge: trust) {
            outDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n-1 && outDegree[i] == 0)
                return i;
        }

        return -1;
    }
};