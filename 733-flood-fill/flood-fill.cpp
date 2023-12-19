class Solution {
private:
    void dfs(vector<vector<int>> &ans, int delRow[], int delCol[], int &initialColor, int &row, int &col , int &newColor) {
        ans[row][col] = newColor;
        int n = ans.size();
        int m = ans[0].size();

        for(int i = 0; i < 4; i++) {   
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor) {
                dfs(ans, delRow, delCol, initialColor, nrow, ncol, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ans = image;
        int initialColor = image[sr][sc];
        
        int delRow[] = { -1, 0, 1, 0};
        int delCol[] = { 0, 1, 0, -1};

        dfs(ans, delRow, delCol, initialColor, sr, sc, newColor);

        return ans;
    }
};