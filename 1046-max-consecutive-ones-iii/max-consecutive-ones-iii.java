class Solution {
    public int longestOnes(int[] nums, int k) {
        int left = 0;
        int right = 0;
        int maxLength = 0, n = nums.length, zeroCount = 0;

        //the problem statement could be rewritten as 
        //longest substring with atmost k zeros in it

        while (right < n) {

            if ( nums[right] == 0 )
                zeroCount++;
            if (zeroCount > k) {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }

            if (zeroCount <= k)
                maxLength = Math.max(maxLength, right - left + 1);

            right++;
        }

        return maxLength;
    }
}