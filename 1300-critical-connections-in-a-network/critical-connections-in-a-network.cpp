class Solution {
private:
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int> &vis,
            vector<int> adj[], int timeIn[], int low[], vector<vector<int>> &bridges) {
                vis[node] = 1;
                timeIn[node] = low[node] = timer;
                timer++;

                for(auto it: adj[node]) {
                    if (it == parent) continue; //skip the parent
                    if (vis[it] == 0) {
                        //if not visited
                        dfs(it, node, vis, adj, timeIn, low, bridges);
                        //when it is returning get the lowest possibe number 
                        low[node] = min(low[node], low[it]);
                        // node --- it is it a bridge lets check
                        if (low[it] > timeIn[node]) {
                            //if the lowest of the adj node is greater than 
                            //the current node means there is bridge that it 
                            //can't reach the current node by some other node
                            bridges.push_back({it, node});
                        }
                    }
                    else {
                        //if it is visited
                        //just take the lowest one if there and move
                        low[node] = min(low[node], low[it]);
                    }
                }
            }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //first create the adjacency list
        vector<int> adj[n];
        for(auto it: connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //for dfs traversal
        vector<int> vis(n, 0);
        //tarjan algorithm we need time and low time data structure array simply
        int timeIn[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, timeIn, low, bridges);
        return bridges;
    }
};