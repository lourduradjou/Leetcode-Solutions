class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool Union(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return false;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return true;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet aliceGraph(n+1);
        DisjointSet bobGraph(n+1);

        int alice_edges = 0;
        int bob_edges = 0;
        int removed_edges = 0;

        for (auto edge : edges) {
            if (edge[0] == 3) {
                if ( aliceGraph.Union(edge[1], edge[2]) ) {
                    bobGraph.Union(edge[1], edge[2]);

                    alice_edges++;
                    bob_edges++;
                }
                else
                    removed_edges++;
            } 
        }

        for (auto edge : edges) {
            if (edge[0] == 2) //bob only
            {
                if ( bobGraph.Union(edge[1], edge[2])) 
                    bob_edges++;
                else 
                    removed_edges++;
            }
            else if (edge[0] == 1){ //alice only
                if ( aliceGraph.Union(edge[1], edge[2])) 
                    alice_edges++;
                else 
                    removed_edges++;
            }
        }

        return (alice_edges == n-1 && bob_edges == n-1) ? removed_edges : -1;
    }
};