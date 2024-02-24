class DisjointSet {
    public:
        vector<int> parent;
        vector<int> rank;
        DisjointSet(int n) {
            parent.resize(n, 0);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) 
                parent[i] = i;
        }

        int find(int node) {
            return parent[node] = (parent[node] == node) ? node: find(parent[node]);
        }

        void reset(int node) {
            parent[node] = node;
        }

        void Union(int nodeA, int nodeB) {
            int uParA = find(nodeA), uParB = find(nodeB);
            if (uParA != uParB) {
                rank[uParA] < rank[uParB] ? parent[uParA] = uParB : parent[uParB] = uParA;
                rank[uParA] += rank[uParA] == rank[uParB] ? 1: 0;
            }
        }
};


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        auto compare = [](const vector<int> &a, const vector<int> &b) {
            if (a[2] == b[2])
                return a[0] < b[0];
            else 
                return a[2] < b[2];
        };
        sort(meetings.begin(), meetings.end(), compare);

        DisjointSet ds(n);
        ds.Union(0, firstPerson);

        for (int i = 0; i < meetings.size();) {
            int currentTime = meetings[i][2];
            vector<int> curPeople;

            while (i < meetings.size() && meetings[i][2] == currentTime) {
                ds.Union(meetings[i][0], meetings[i][1]); //union whatever is in the meeting room
                curPeople.push_back(meetings[i][0]);
                curPeople.push_back(meetings[i][1]);
                i++;
            }
            
            int check = ds.find(0); // simply zero will also work 
            for (auto curPep : curPeople) {
                if (ds.find(curPep) != check)
                    ds.reset(curPep);
            }
        }

        vector<int> ans;
        int check = ds.find(0); // simply zero will also work
        for (int i = 0; i < n; i++) {
            if (ds.find(i) == check)
                ans.push_back(i);
        }
        return ans;
    }
};