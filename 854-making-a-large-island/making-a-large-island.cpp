class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
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
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
private:
    bool isValid(int newRow, int newCol, int n) {
        return newRow >= 0 && newRow < n && newCol >= 0 && newCol < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        //first create the components
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;
                int rowDimension[] = {-1, 0, 1, 0};
                int colDimension[] = {0, 1, 0, -1};
                for(int ind = 0; ind < 4; ind++) {
                    int newRow = row + rowDimension[ind];
                    int newCol = col + colDimension[ind];
                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int nodeNumber = row * n + col;
                        int adjNodeNumber = newRow * n + newCol;
                        ds.unionBySize(nodeNumber, adjNodeNumber);
                    }
                }
            }
        }
        //step 2 is to find the maximum count of island after turning one zero to one
        int maxSize = -1;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {

                if(grid[row][col] == 1) continue;
                int rowDimension[] = {-1, 0, 1, 0};
                int colDimension[] = {0, 1, 0, -1};
                unordered_set<int> components;

                for(int ind = 0; ind < 4; ind++) {
                    int newRow = row + rowDimension[ind];
                    int newCol = col + colDimension[ind];
                    if( isValid(newRow, newCol, n) ) {
                       //my adj node should be a one so that i can connect the components
                       if( grid[newRow][newCol] == 1 ) {
                           components.insert(ds.findUPar(newRow * n + newCol));
                       }
                    }
                }

                int totalSize = 0;
                for(auto it: components) {
                    totalSize += ds.size[it];
                }
                maxSize = max(maxSize, totalSize + 1);
            }            
        }
        return maxSize == -1 ? ds.size[ds.findUPar(1)] : maxSize;
    }
};