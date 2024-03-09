class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int i = 0, j = 0;
        int array_one_size = nums1.length;
        int array_two_size = nums2.length;

        while ( i < array_one_size && j < array_two_size ) {
            if (nums1[i] == nums2[j])
                return nums1[i];
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return -1;
    }
}