class DisjointSet {
    private:
        vector<int> size;
        vector<int> parent;
    
    public:
        DisjointSet(int n) {
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findParent(int u) {
            if (u == parent[u])
                return u;
            return parent[u] = findParent(parent[u]);
        }

        void unionBySize(int u, int v) {
            int up_u = findParent(u);
            int up_v = findParent(v);
            if (up_u == up_v) 
                return ;
            
            if(size[up_u] > size[up_v]) {
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }
            else {
                parent[up_u] = up_v;
                size[up_v] += size[up_u];
            }
        }
};

class Solution {
private:
    bool isValid(int newRow, int newCol, int n) {
        return newRow >= 0 && newRow < n && newCol >= 0 && newCol < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        //to the element i and j store it in the map
        unordered_map<int, pair<int,int>> mpp;
        int n = grid.size();

        if( n == 1 ) return 0; // if n is 1 in 0 time it can reach

        DisjointSet ds(n*n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mpp[grid[i][j]] = {i,j};
            }
        }

        int time = 0;
        while ( ds.findParent(0) != ds.findParent(n*n - 1) ) {
            auto elementPosition = mpp[time];
            int x = elementPosition.first;
            int y = elementPosition.second;

            int rowDimension[] = {-1, 0, 1, 0};
            int colDimension[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int newRow = x + rowDimension[i];
                int newCol = y + colDimension[i];

                if(isValid(newRow, newCol, n) && grid[newRow][newCol] <= time) {
                    ds.unionBySize(newRow * n + newCol, x * n + y);
                }
            }
            time++;
        }

        return time - 1;
    }
};