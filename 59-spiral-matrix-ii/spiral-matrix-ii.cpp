class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiralOrder(n, vector<int>(n,0));
        int k = 0;

        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for(int i = left; i <= right; i++) {
                spiralOrder[top][i] = ++k;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                spiralOrder[i][right] = ++k;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    spiralOrder[bottom][i] = ++k;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    spiralOrder[i][left] = ++k;
                }
                left++;
            }

        }

        return spiralOrder;
    }
};