class Solution {
    private int n;
    private int[][] dp = new int [100000][3];

    public int maxTwoEvents(int[][] events) {
        n = events.length;
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0])); // sort by starting value

        for (int[] row: dp) {
            Arrays.fill(row, -1);
        }

        return solve(events, 0, 0); // events, index, count (max 2 required here)
    }

    private int solve(int[][] events, int i, int count) {
        if (count >= 2 || i >= n) {
            return 0;
        }

        if (dp[i][count] != -1) {
            return dp[i][count];
        }

        int nextValidIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidIndex, count + 1);
        int notTake = solve(events, i + 1,count);

        dp[i][count] = Math.max(take, notTake);
        return dp[i][count];
    }

    private int binarySearch(int[][] events, int endTime) {
        int left = 0, right = n-1, result = n; // n would stop the recursion note

        while (left <= right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > endTime) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
}