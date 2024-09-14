class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxCherriesPath(vector<vector<int>> &grid, int row_loc, int robot1_loc, int robot2_loc, int rows, int cols, 
    vector<vector<vector<int>>>& dp) {
        if (robot1_loc < 0 || robot1_loc >= cols || robot2_loc < 0 || robot2_loc >= cols) {
            return -1e8;
        }

        if (row_loc == rows-1) {
            if (robot1_loc == robot2_loc) return grid[row_loc][robot1_loc]; //we can also use roboto2_loc, anyway they are same
            else {
                return grid[row_loc][robot1_loc] + grid[row_loc][robot2_loc];
            }
        }

       

        if (dp[row_loc][robot1_loc][robot2_loc] != -1) 
            return dp[row_loc][robot1_loc][robot2_loc];

        int maxi = -1e8;

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = 0;
                if (robot1_loc == robot2_loc) value = grid[row_loc][robot1_loc]; //we can also use roboto2_loc, anyway they are same
                else {
                    value = grid[row_loc][robot1_loc] + grid[row_loc][robot2_loc];
                }
                value += findMaxCherriesPath(grid, row_loc + 1, robot1_loc + dj1, robot2_loc + dj2, rows, cols, dp);
                maxi = max(maxi, value);
            }
        }

        return dp[row_loc][robot1_loc][robot2_loc] = maxi;
        
    }


    int cherryPickup(vector<vector<int>>& grid) {
        //this is a 3d dynamic array approaching problem interesting actually
        int n = grid.size(); //rows size
        int m = grid[0].size(); //columns size
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

        return findMaxCherriesPath(grid, 0, 0, m-1, n, m, dp);
    }
};