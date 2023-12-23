class Solution {

private:
    bool check(int nrow, int ncol, int n, int m, vector<vector<int>> &vis) {
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
            return true;
        else 
            return false;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> dis(n, vector<int> (m, 0));

        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push( {{i,j}, 0});
                }
            }
        }

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};

        while( !q.empty() ) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;

            for(int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if( check(newRow, newCol, n , m, vis) ) 
                {
                    vis[newRow][newCol] = 1;
                    q.push( {{newRow, newCol}, steps+1} );
                }
            }
        }

        return dis;
    }
};