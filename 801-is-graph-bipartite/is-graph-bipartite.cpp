class Solution {
private:
    bool check(int start, int V, vector<int> adj[], vector<int> &color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while( !q.empty() ) {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                if(color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //run a loop for multiple components also
        //here instead of vis array we are using a color ,
        //same as vis but here starting will be -1 and 0 , 1 are
        //used to represent different colors, usual bfs stuffs
        int V = graph.size();
        //we need to create the vis list here
        vector<int> adj[V];
        int i = 0;
        for(auto vec : graph) {
            adj[i++] = vec;
        }

        vector<int> colors(V, -1);
        
        for(int i = 0; i < V; i++) {
            if(colors[i] == -1) {
                if(check(i, V, adj, colors) == false)
                    return false;
            }
        }
        
        return true;
    }
};