class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //here they asking for min rather than max, same 2d dp
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,-1);
        //initialization
        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < m; i++) {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++) {
                int leftDia = 1e8, rightDia = 1e8;
                int up = matrix[i][j] + prev[j];
                if(j > 0) leftDia = matrix[i][j] + prev[j-1];
                if(j < n-1) rightDia = matrix[i][j] + prev[j+1];

                cur[j] = min({up, leftDia, rightDia});
            }
            prev = cur;
        }

        int mini = 1e8;
        
        for (int j = 0; j < n; j++) {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};