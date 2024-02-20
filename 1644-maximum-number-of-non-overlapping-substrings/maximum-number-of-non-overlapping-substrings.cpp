class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &finishTime) {
        vis[node] = 1;
        for (auto it: adj[node]) {
            if (!vis[it]) 
                dfs(it, adj, vis, finishTime);
        }
        finishTime.push_back(node);
    }

    void dfs2(int node, vector<vector<int>> &adjT, vector<int> &vis, vector<int> &temp) {
        vis[node] = 1;
        if(adjT[node].size() == 0) return;
        temp.push_back(node);

        for(auto it: adjT[node]) {
            if (!vis[it]) {
                dfs2(it, adjT, vis, temp);
            }
        }
    }

    void dfsCheck_Outdegree(int node, vector<vector<int>> &adj, map<int,int> &mp, vector<int> &visited, bool &flg) {
        visited[node] = 1;
        for(auto it: adj[node]) {
            if (mp[it] != 1) {
                flg = false;
                return;
            }
            if (!visited[it]) 
                dfsCheck_Outdegree(it, adj, mp, visited, flg);
        }
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> firstOccurance(26, INT_MAX), lastOccurance(26, INT_MIN); 
        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            firstOccurance[index] = min(firstOccurance[index], i);
            lastOccurance[index] = i;
        }

        vector<vector<int>> adj(27);
        //creating the graph
        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            for(int j = 0; j < 26; j++) {
                if (firstOccurance[index] != INT_MAX) {
                    if(firstOccurance[j] <= i && lastOccurance[j] >= i)
                        adj[j].push_back(index);
                }
            }
        }

        //step 1
        //perform dfs and find the endtime here lets use a vector
        //instead of stack to make it easy ..
        n = 26;
        vector<int> finishTime;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, adj, vis, finishTime);
        }

        //step 2 is to reverse the edges betweene each vertices
        vector<vector<int>> adjT(n);
        for(int i = 0; i < n; i++) {
            for(auto it: adj[i]) {
                adjT[it].push_back(i);
            }
        }

        //step 3 is to iterate using dfs and find the scc 
        vector<int> v(n,0); //reassigning the vis to use it again
        vector<vector<int>> scc;
        for(int i = n-1; i >= 0; i--) {
            int node = finishTime[i];
            if (!v[node]) {
                vector<int> temp;
                dfs2(node, adjT, v, temp);
                scc.push_back(temp);
            }
        }


        vector<string> ans;
        for (auto it: scc) {
            vector<int> visited(n, 0);

            if(it.size() != 0) {
                map<int, int> mp;
                for(auto ele: it) mp[ele] = 1;
                bool flg = true;
                dfsCheck_Outdegree(it[0], adj, mp, visited, flg);
                
                //if there is not outdegree
                //this algo picks up the lowest index and high index withing that scc
                //out degree is indicated by this flg variable , true means no outdegree
                if (flg == true) {
                    int minIndex = 1e9, maxIndex = -1;
                    for(auto ele: it) {
                        minIndex = min(minIndex, firstOccurance[ele]);
                        maxIndex = max(maxIndex, lastOccurance[ele]);
                    }
                    ans.push_back(s.substr(minIndex, maxIndex - minIndex + 1));
                }
            }
        }

        return ans;
    }
};