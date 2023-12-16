class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //we gotta iterate through the grid first n2
        //then call the bfs or dfs in worst case it would n2 
        //then call the bfs for the surrounded eight directions so would take 8
        //in total n2 + n2 * 8 = n2
        //sc: n2 rounded with vis matrix and queue

        int n = grid.size(); //row size;
        int m = grid[0].size(); //column size;
        int count = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if( !vis[row][col] && grid[row][col] == '1' ) {
                    count++;
                    dfs(grid, row, col, vis);               
                }

            }
        }

        return count;
    }

    void dfs( vector<vector<char>> &grid, int row, int col, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int inRow = -1; inRow <= 1; inRow++) {
            for(int inCol = -1; inCol <= 1; inCol++) {
                
                int newRow = row + inRow;
                int newCol = col + inCol;

                if(inRow != 0 && inCol != 0) 
                    continue;
                //in this problem we gotta check only the four directions 
                //so check that only when both of the inrow and incol are not 
                //equal to zero means it is diagonal direction so skip it.
                if( newRow >= 0 && newRow < n && newCol >= 0 && 
                newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == '1' ) {
                    dfs(grid, newRow, newCol, vis);
                }            
            }                
        }
    }
};