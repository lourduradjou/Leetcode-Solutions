/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void inorder_traversal(TreeNode root, ArrayList<Integer> arr) {
        if(root == null) return;
        inorder_traversal(root.left, arr);
        arr.add(root.val);
        inorder_traversal(root.right, arr);
    }
    public int getMinimumDifference(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        inorder_traversal(root, arr);
        int n = arr.size();
        int minValue = Integer.MAX_VALUE;
        for(int i = 0; i < n-1; i++) {
            minValue = Math.min(minValue, arr.get(i+1) - arr.get(i));
        }
        return minValue;
    }
}

