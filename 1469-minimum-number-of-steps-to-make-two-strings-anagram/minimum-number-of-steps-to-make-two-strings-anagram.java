class Solution {
    public int minSteps(String s, String t) {
        int[] countStringOne = new int[26];
        int[] countStringTwo = new int[26];

        for (int i = 0; i < s.length(); i++) {
            countStringOne[s.charAt(i) - 'a']++;
            countStringTwo[t.charAt(i) - 'a']++;
        }

        int stepsRequired = 0;
        for (int i = 0; i < 26; i++) {
            stepsRequired += Math.abs(countStringOne[i] - countStringTwo[i]);
        }

        return stepsRequired / 2;
    }
}
