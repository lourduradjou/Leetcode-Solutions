class Solution {

public:
    int uniquePaths(int m, int n) {
        //space optimized approach using a single row on top of the matrix!
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) cur[j] = 1;
                else{
                    int up = 0, left = 0; 
                    //we are taking the left and top just because fromt that
                    //way only you could have get into the current point
                    //so could their paths, simple!
                    if (i > 0) up = prev[j];
                    if (j > 0) left = cur[j-1];

                    cur[j] = up + left;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};

