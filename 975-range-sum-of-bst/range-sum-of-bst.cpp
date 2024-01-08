/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* node, int& low, int& high, int& ans) {
        if(node == NULL)    
            return;
        //preorder traverse;
        solve(node->left, low, high, ans);
        solve(node->right, low, high, ans);

        if(node->val >= low && node->val <= high)
            ans += node->val;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        solve(root, low, high, ans);
        return ans;
    }
};