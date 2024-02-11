class Solution {
public:
    int dp[51][51][51];
    bool is_NotAllowed(int row1, int col1, int row2, int col2, vector<vector<int>> &grid) {
        if(row1 >= grid.size() || row2 >= grid.size() || col1 >= grid[0].size() || col2 >= grid[0].size() || grid[row1][col1] == -1 || grid[row2][col2] == -1) {
            return true;
        }
        return false; //it is not crossing the boundaries of the matrix
    }

    int findPaths(int row1, int col1, int row2, vector<vector<int>> &grid) {
        int col2 = row1 + col1 - row2; //r1 + c1 = r2 + c2 => c2 = r1 + c1 - r2;
        if(is_NotAllowed(row1, col1, row2, col2, grid))
            return INT_MIN;

        if(row1 == grid.size()-1 && col1 == grid[0].size()-1)
            return grid[row1][col1];

        if(dp[row1][col1][row2] != 0)
            return dp[row1][col1][row2];
        
        int cherries = 0;
        if(row1 == row2 && col1 == col2) // if both bots stand at same location take one 
            cherries += grid[row1][col1];
        else 
            cherries += (grid[row1][col1] + grid[row2][col2]);
        
        int cnt1 = findPaths(row1, col1 + 1, row2, grid); // h h
        int cnt2 = findPaths(row1 + 1, col1, row2, grid); // v h
        int cnt3 = findPaths(row1, col1 + 1, row2 + 1, grid); // h v
        int cnt4 = findPaths(row1 + 1, col1, row2 + 1, grid); // v v

        cherries += max({cnt1, cnt2, cnt3, cnt4});
        return dp[row1][col1][row2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, 0, sizeof(dp));
        int ans = findPaths(0, 0, 0, grid);
        return (ans < 0) ? 0: ans;
    }
};