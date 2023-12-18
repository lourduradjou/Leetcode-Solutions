class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //we are using a queue and countMin to solve this problem
        //ofcourse like a bfs using queue right
        //kinda get all the rottens first in the queue and then
        //try to get the fresh and make them rotten if possible or don't
        //comparet the total count and how much we got in our queue
        //if matched every fresh orange is converted to rotten else not
        if(grid.empty()) return 0;

        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> rotten;
        int tot = 0, time = 0, innerCnt = 0;

        for(int i = 0; i < n; i++) {
            for( int j = 0; j < m; j++) {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};

        while( !rotten.empty() ) //base condition for bfs
        {
            int cnt = rotten.size();
            innerCnt += cnt;

            while( cnt-- ) {
                int row = rotten.front().first;
                int col = rotten.front().second;
                rotten.pop();

                for(int i = 0; i < 4; i++) {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m) {
                        if (grid[nRow][nCol] != 1) 
                            continue;
                        // After getting a fresh orange, make it rotten and push the indexes
                        grid[nRow][nCol] = 2;
                        rotten.push({nRow, nCol});
                    }

                }
            }

            if( !rotten.empty() ) time++;
        
        }

        if( tot == innerCnt ) return time;
        else return -1;

    }
};