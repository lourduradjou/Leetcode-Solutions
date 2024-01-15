class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1|| grid[n-1][m-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 1;
        //here instead of storing the dis in the queue we are using
        //a seperate the vector
        int rowDimension[] = {0, 1, 1, 1, 0, -1, -1 ,-1};
        int colDimension[] = {1, 1, 0, -1, -1, -1, 0, 1};

        while(!q.empty()) {
            auto dim  = q.front();
            int row = dim.first;
            int col = dim.second;
            q.pop();

            for(int i = 0; i < 8; i++) {
                int newRow = row + rowDimension[i];
                int newCol = col + colDimension[i];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && dist[row][col] + 1 < dist[newRow][newCol]) {
                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        if(dist[n-1][m-1] == INT_MAX) return -1;
        else return dist[n-1][n-1];
    }
};