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
    bool dfs(TreeNode *root, int sum, int curr) {
        if (root == NULL) return false;

        curr += root->val;

        if (curr == sum && root->left == NULL && root->right == NULL) 
            return true;
        
        if (dfs(root->left, sum, curr) || dfs(root->right, sum, curr)) 
            return true;

        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);      
    }
};
