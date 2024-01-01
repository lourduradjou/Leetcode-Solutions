class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Using topo sort we can find the nodes which are actually in the cycle 
        //we can avoid that and put the safenodes alone and along the way 
        //toposort will take the ones which are indegree or zero and here in eventual safe we need outdegree of zero
        //so first reverse the adj list and sort the topo sort to work with outdegree
        int V = graph.size();
        vector<int> adjRev[V];
        vector<int> inDegree(V, 0);
        for(int i = 0; i < V; i++) {
            //i -> it;
            //it -> i;
            for(auto& it: graph[i]) {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        //now the revAdj list was ready
        //so start bfs topo sort
        queue<int> q;
        vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            //if the node is in the queue surely it doesnt have any outdegree so terminal node
            for(auto& it: adjRev[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};