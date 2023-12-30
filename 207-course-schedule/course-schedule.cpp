class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         //we are using topological sort method to schedule 
    //it is just if there is a cycle we can't form or can form thats all here i am using bfs 
    //in dfs just use a stack it is also easy
    int V = numCourses;
    vector<int> adj[V];
    for(auto it: prerequisites) {
        adj[it[1]].push_back(it[0]);
    }
    
    vector<int> inDegree(V, 0);
    for(int i = 0; i < V; i++) {
        for(auto it: adj[i])
            inDegree[it]++;
    }
    
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0)
            q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto adjNode: adj[node]) {
            inDegree[adjNode]--;
            if(inDegree[adjNode] == 0)
                q.push(adjNode);
        }
    }
    
    // cout<<V<<endl;
    if(ans.size() == V)
        return true;
    else 
        return false;
    }
};