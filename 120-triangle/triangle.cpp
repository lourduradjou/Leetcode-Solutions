class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> front(n,0);
        for (int i = n-1; i >= 0; i--) {
            front[i] = triangle[n-1][i];
        }
        //we tried to go from top to bottom in memo with 0 to the bottom 
        //in tabu it is the opposite 
        for (int i = n-2; i >= 0; i--) {
            vector<int> cur(i+1, 0);
            for (int j = i; j >= 0; j--) {
                if (i == n-1) cur[j] = triangle[i][j];
                else {
                    int down = triangle[i][j] + front[j];
                    int diaRight = triangle[i][j] + front[j+1];

                    cur[j] = min(down, diaRight);
                }
            }
            front = cur;
        }

        return front[0];
    }
};