class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int,int>> q;

        //store all the corner 'O' elements in the queue and its corresponding 
        //touching 'O' also so that we can fianlly avoid those ones by using vis vector

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0 && i < n-1 && j > 0 && j < m-1)
                    continue;
                if(board[i][j] == 'O') {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while( !q.empty() ) {
            auto [x,y] = q.front();
            q.pop();
            for(auto ele: dir) {
                int row = x + ele[0];
                int col = y + ele[1];
                //check the row and col is valid within the boundary and also it is 'O'
                if(row >= 0 && row < n && col >= 0 && col < m && board[row][col] == 'O' && vis[row][col] == 0) {
                    vis[row][col] = 1;
                    q.push({row, col});
                }
            }
        }
        //the queue loop will make to mark all the 'O' which are connected to the boundary
        //'O' through the four directions so that we can avoid it.

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && board[i][j] == 'O')//we are trying to change
                //the 'O' to x only if it is not visited by the boundary ones
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};