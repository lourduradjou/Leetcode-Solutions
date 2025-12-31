class Solution {

    int ROW;
    int COL;

    int[][] directions = {{1,0}, {-1, 0}, {0,1}, {0, -1}};

    private boolean isNotValid(int[][] grid, int i, int j) {
        if (i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] == 1) {
            return true;
        }

        return false;
    }

    private boolean dfs(int[][] grid, int i, int j) {
        if (isNotValid(grid,i, j)) {
            return false;
        }

        if (i == ROW - 1) {
            return true; // we reached the final row
        }

        grid[i][j] = 1;

        for (int[] dir: directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];

            if (dfs(grid, newI, newJ)) {
                return true;
            }
        }

        return false;
    }

    private boolean canCross(int[][] cells, int day) {
        int[][] grid = new int[ROW][COL];

        for (int i = 0; i <= day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1; // it is occupied
        }

        // after creating the grid , try whether the dfs pos or not
        for (int i = 0; i < COL; i++) {
            if (grid[0][i] == 0 && dfs(grid, 0, i)) {
                return true; //where it means we can go to the very bottom, with that i'th column 
            }
        }

        // after trying every solution return false
        return false;
    }

    public int latestDayToCross(int row, int col, int[][] cells) {
        ROW = row;
        COL = col;

        int left = 0;
        int right = cells.length - 1;
        int lastDay = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (canCross(cells, mid)) {
                lastDay = mid + 1; // because one based indexing
                left = mid + 1; // lets evaluate the right side
            } else {
                right = mid - 1; // lets shrink down the right side to the left
            }
        }

        return lastDay;
    }
}