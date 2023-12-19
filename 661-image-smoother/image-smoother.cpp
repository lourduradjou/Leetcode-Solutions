class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int rowSize = img.size();
        int colSize = img[0].size();
        vector<vector<int>> ans(rowSize, vector<int> (colSize, 0));

        for(int row = 0; row < rowSize; row++) {
            for(int col = 0; col < colSize; col++) {
                int totalSum = 0;
                int count = 0;
                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        int newRow = row + i;
                        int newCol = col + j;
                        if( newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize)
                        {
                            totalSum += img[newRow][newCol];
                            count += 1;
                        }
                    }
                }
                ans[row][col] = totalSum / count;
            }
        }

        return ans;
    }
};