class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto &it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        //adj list was done so create pq for iteration 
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while( !pq.empty() ) {
            int currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if(currTime > time[currNode])
                continue;

            //iterate through the adjacent node using adj list
            for(auto it: adj[currNode]) {
                int adjNode = it.first;
                int extraTime = it.second;
                if(currTime + extraTime < time[adjNode]) {
                    pq.push({currTime + extraTime , adjNode});
                    time[adjNode] = currTime + extraTime;
                }
            }
        }

        int ans = INT_MIN; //cause we wanna find the max time it took in the shortest path among all ..
        for(int i = 1; i <= n; i++) {
            ans = max(ans, time[i]);
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};