class Solution {
    private int isPalindrome(String s, int i, int j ) {
        while(i <= j) {
            if(s.charAt(i++) != s.charAt(j--)) return 0;
        }
        return 1;
    }
    public int countSubstrings(String s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                count += isPalindrome(s, i , j);
            }
        }

        return count;
    }
}