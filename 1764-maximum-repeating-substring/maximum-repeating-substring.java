class Solution {
    int[] dp;
    public int maxRepeating(String sequence, String word) {
        dp = new int[sequence.length()];
        int ans = 0;

        for (int i = 0; i < sequence.length(); i++) {
            ans = Math.max(ans, solve(sequence, word, i));
        }

        return ans;
    }

    private int solve(String sequence, String word, int index) {
        if (index + word.length() > sequence.length()) 
            return 0;
        
        if (dp[index] != 0) {
            return dp[index];
        }

        if (sequence.startsWith(word, index)) {
            return dp[index] = 1 + solve(sequence, word, index + word.length());
        }

        return dp[index] = 0;
    }
}