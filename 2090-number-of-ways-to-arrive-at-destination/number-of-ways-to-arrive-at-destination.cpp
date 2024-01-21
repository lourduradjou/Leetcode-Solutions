class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //just use an extra ways array to find the number of ways a shortest path 
        //can me made to the destination node
        //simpel dijstra will work here
        //steps create adj list, ways , dist array and pq and iterate over there
        vector<pair<long long,long long>> adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LONG_MAX), ways(n,0);
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>>> pq;

        dist[0] = 0;
        ways[0] = 1; //src or starting node has 1 way initially
        pq.push({0,0}); //we can reach src 0 with a distance of 0,{distance, src};
        const long long MOD = (long long)1e9 + 7;

        while( !pq.empty() ) {
            long long distance = pq.top().first;
            long long currNode = pq.top().second;
            pq.pop();

            for(auto it: adj[currNode]) {
                long long adjNode = it.first;
                long long extraDistance = it.second;
                if((distance + extraDistance) < dist[adjNode]) {
                    dist[adjNode] = distance + extraDistance;
                    pq.push({distance + extraDistance, adjNode});
                    ways[adjNode] = ways[currNode];
                }
                else if(distance + extraDistance == dist[adjNode]) {
                    ways[adjNode] = ((long long)(ways[adjNode]) + ways[currNode]) % MOD;
                }
            }
        }

        return (int)(ways[n-1] % MOD);
    }
};