class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(); //number of rows
        int n = grid[0].size(); //number of columns

        vector<int> rowOnesCount(m, 0);
        vector<int> columnOnesCount(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowOnesCount[i] += grid[i][j];
                columnOnesCount[j] += grid[i][j];
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = 2 * (rowOnesCount[i] + columnOnesCount[j]) - m - n;
                //this is derived formula to remove the
                //expression of zeros count from the mathematical equation .
            }
        }

        return grid;
    }
};