class Solution {
    public int minDeletionSize(String[] strs) {
        int arrLength = strs.length;
        int strLength = strs[0].length();
        int delCount = 0;
        boolean badPair;

        boolean[] sortedStrings = new boolean[arrLength - 1];
        int unsortedCount = arrLength - 1;

        for (int i = 0; i < strLength && unsortedCount > 0; i++) {
            badPair = false;

            for (int j = 0; j < arrLength-1; j++) {
                // System.out.println(strs[j].charAt(i));
                if (!sortedStrings[j] && strs[j].charAt(i) > strs[j+1].charAt(i)) {
                    badPair = true;
                    break;
                }
            }

            if (badPair) {
                delCount++;
                continue;
                //no need to check for sorted string below
            }


            for (int j = 0; j < arrLength-1; j++) {
                if (!sortedStrings[j] && strs[j].charAt(i) < strs[j+1].charAt(i)) {
                    sortedStrings[j] = true;
                    unsortedCount--;
                }
            }

        }

        return delCount;
    }
}