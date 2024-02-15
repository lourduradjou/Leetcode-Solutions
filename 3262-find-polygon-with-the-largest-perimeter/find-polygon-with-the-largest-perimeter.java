class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long  maximumPerimeter = Integer.MIN_VALUE;
        long prefixSum = nums[0] + nums[1];

        for (int i = 2; i < nums.length; i++) {
            if (prefixSum > (long)nums[i]) {
                maximumPerimeter = Math.max(maximumPerimeter, prefixSum + nums[i]);
            }
            prefixSum += nums[i];
        }

        return (maximumPerimeter == Integer.MIN_VALUE) ? -1 : maximumPerimeter;
    }
}


