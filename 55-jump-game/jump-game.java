class Solution {
    public boolean canJump(int[] nums) {
        int reachableDistance = 0;
        int nextReachable = 0;

        for (int i = 0; i < nums.length; i++) {
            if (i > reachableDistance) return false;
            nextReachable = i + nums[i];
            reachableDistance = Math.max(reachableDistance, nextReachable);
        }

        return true;
    }
}