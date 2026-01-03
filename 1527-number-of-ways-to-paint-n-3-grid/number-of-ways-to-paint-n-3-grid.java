class Solution {
    int MOD = 1_000_000_007;
    int[][] dp;

    String[] states = {
        "RYG", "RGY", "RYR", "RGR",
        "YRG", "YGR", "YGY", "YRY",
        "GRG", "GYR", "GRY", "GYG"
    };

    public int numOfWays(int n) {
        dp = new int[n][12]; // n rows and 12 possible ways within that state

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        int result = 0;

        for (int i = 0; i < 12; i++) {
            result = (result + solve(n-1, i)) % MOD;
        }

        return result;
    }

    private int solve(int row, int prev) {
        if (row == 0)
            return 1; // we reached a unique solution
        
        if (dp[row][prev] != -1)
            return dp[row][prev];
        
        int result = 0;
        String last = states[prev];

        for (int cur = 0; cur < 12; cur++) {
            if (cur == prev) {
                continue; // obviously they are gonna be same
            }

            String currPattern = states[cur];
            boolean conflict = false;
            
            for (int col = 0; col < 3; col++) {
                if (currPattern.charAt(col) == last.charAt(col)) {
                    conflict = true;
                    break;
                }
            }

            if (!conflict) {
                result = (result + solve(row-1, cur)) % MOD;
            }
        }


        return dp[row][prev] = result;
    }
}