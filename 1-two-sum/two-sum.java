class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numsMap = new HashMap<>();
        int n = nums.length;

        for(int i = 0; i < n; i++) {
            int diffNeed = target - nums[i];
            
            if (numsMap.containsKey(diffNeed)) {
                return new int[]{numsMap.get(diffNeed), i};
            }

            numsMap.put(nums[i], i);
        }

        return new int[]{};
    }
}