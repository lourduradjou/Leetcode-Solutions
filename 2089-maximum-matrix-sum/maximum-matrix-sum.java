class Solution {
    public long maxMatrixSum(int[][] matrix) {
        // find the abs sum 
        int n = matrix.length;
        int m = matrix[0].length;
        long negCount = 0, absSum = 0, minNum = Integer.MAX_VALUE; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                absSum += Math.abs(matrix[i][j]);
                minNum = Math.min(minNum, Math.abs(matrix[i][j]));
                if (matrix[i][j] < 0) negCount += 1;
            }
        }

        if (negCount % 2 == 1) {
            // if it is odd;
            System.out.println(minNum);
            absSum -= (2 * minNum);
        }

        return absSum;
    }
}