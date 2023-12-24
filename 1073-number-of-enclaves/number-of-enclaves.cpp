class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        
        for(int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == 1)
                dfs(newRow, newCol, vis, grid, n, m, delRow, delCol);
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //we have to find from what cells if we move we can't move out of the land 
        //we can use a vis matrix and dfs to find this
        //start with the boundary if there is a 1 start dfs and mark all the connected cells
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( (i == 0 || i == n-1 || j == 0 || j == m-1) && !vis[i][j] && grid[i][j] == 1 ) 
                    dfs(i, j, vis, grid, n, m, delRow, delCol);
            }
        }

        int countCells = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1)
                    countCells++;
            }
        }

        return countCells;
    }
};