class Solution {
    public int minDeletionSize(String[] strs) {
        int strLength = strs[0].length();
        int arrLength = strs.length;

        int[] maxValidSequence = new int[strLength];
        Arrays.fill(maxValidSequence, 1);

        for (int end = 1; end < strLength; end++) {
            for (int start = 0; start < end; start++) {
                if (isValidSequence(strs, start, end)) {
                    maxValidSequence[end] = Math.max(maxValidSequence[end], maxValidSequence[start] + 1);
                }
            }
        }

        //pick the max and subtract with the original string size to get the count of the 
        //letters/columns that has to be deleted so,..

        int maxValidSequenceLength = 0;
        for (int val: maxValidSequence) {
            maxValidSequenceLength = Math.max(maxValidSequenceLength, val);
        }
        
        return strLength - maxValidSequenceLength;

    }

    protected boolean isValidSequence(String[] strs, int start, int end) {
        for (String str: strs) {
            if (str.charAt(start) > str.charAt(end))
                return false;
        }
        return true;
    }
}