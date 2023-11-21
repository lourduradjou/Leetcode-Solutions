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
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    int dfs(TreeNode *node) {
        //exit condition;
        if(node == NULL) return 0;

        int leftHeight = dfs(node->left);
        if(leftHeight == -1)
            return -1;

        int rightHeight = dfs(node->right);
        if(rightHeight == -1) 
            return -1;

        if(abs(rightHeight - leftHeight) > 1)
            return -1;
        
        return 1 + max(leftHeight, rightHeight);
    }

};