class Solution {
    public int maxScore(int[] nums) {
        long sum = 0;
        int n = nums.length;
        int i = 0;
        Arrays.sort(nums);

        for (int j = 0; j < n / 2; j++) {
            int temp = nums[j];
            nums[j] = nums[n - 1 - j];
            nums[n - 1 - j] = temp;
        }

        while ( i < n ) {
            sum += nums[i];
            if (sum <= 0) return i;
            i++;
        }

        return i;
    }
}