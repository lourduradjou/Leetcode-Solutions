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
                for(int i = max(0, row - 1); i < min(rowSize, row + 2); i++) {
                    for(int j = max(0, col - 1); j < min(colSize, col + 2); j++) {
            
                            totalSum += img[i][j];
                            count += 1;
                        
                    }
                }
                ans[row][col] = totalSum / count;
            }
        }

        return ans;
    }
};