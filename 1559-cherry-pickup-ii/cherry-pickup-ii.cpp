class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxCherriesPath(vector<vector<int>> &grid, int i, int robot1j, int robot2j) {
        if(i == grid.size()) return 0; //i reaches last row
        if(robot1j < 0 || robot1j >= grid[0].size() || robot2j < 0 || robot2j >= grid[0].size()) return 0; //column indexing croses the matrix

        if(dp[i][robot1j][robot2j] != -1) return dp[i][robot1j][robot2j];

        int result = 0;
        result += grid[i][robot1j];
        if(robot1j != robot2j) result += grid[i][robot2j];

        int maxForNextRow = 0;
        for(int x = robot1j - 1; x <= robot1j + 1; x++) {
            for(int y = robot2j - 1; y <= robot2j + 1; y++) {
                //this make loop over all the nine possibilities in the matrix;
                maxForNextRow = max(maxForNextRow, findMaxCherriesPath(grid, i+1, x, y));
            }
        }

        result += maxForNextRow;
        return dp[i][robot1j][robot2j] = result;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        //this is a 3d dynamic array approaching problem interesting actually
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<vector<int>>> (m, vector<vector<int>> (n, vector<int> (n, -1)) );
        return findMaxCherriesPath(grid, 0, 0, n-1);
    }
};