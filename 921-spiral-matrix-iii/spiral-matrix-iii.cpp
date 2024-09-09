class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        //lets try this directions rotaion method, 
        //just define the direction change beforehand and start to work , over the iteration
        // 1, 1 ,, 2,2 ,, 3,3 ,, 4,4 ,,  - - - - - - - - - - - - - - - - 
        vector<vector<int>> ans;
        int directions[4][2] = {
            {0,1}, //right side
            {1,0}, //down side
            {0, -1}, //left side
            {-1, 0}, //top side
        };

        int steps = 1;
        int dirIndex = 0;
        int k = 1;

        while ( ans.size() < rows * cols ){ //as far the answer size is less than total size
            for(int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    if ( (rStart >= 0 && rStart < rows) && (cStart >= 0 && cStart < cols) )
                        ans.push_back({rStart, cStart});
                        
                    int dr = directions[dirIndex][0];
                    int dc = directions[dirIndex][1];
                    rStart = dr + rStart;
                    cStart = dc + cStart;
                }
                dirIndex = (dirIndex + 1) % 4;
            }
            steps++;
        }

        return ans;
    }
};