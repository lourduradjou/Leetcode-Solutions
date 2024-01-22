
class Solution {
    private static void dfs(TreeNode root, int sum, int curr, ArrayList<Integer> temp, List<List<Integer>> ans) {
        if (root == null) return;

        curr += root.val;
        temp.add(root.val);

        if (curr == sum && root.left == null && root.right == null) {
            ans.add(new ArrayList<>(temp));
        }

        dfs(root.left, sum, curr, temp, ans);
        dfs(root.right, sum, curr, temp, ans);

        // Backtrack: remove the last element before returning from the current call
        temp.remove(temp.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        dfs(root, targetSum, 0, temp, ans);
        return ans;
    }
}
