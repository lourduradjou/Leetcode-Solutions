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
    int findMaxPathSum(TreeNode* node, int &maxi) {
        if(node == NULL) 
            return 0;
        
        int leftMax = max(0, findMaxPathSum(node->left, maxi));
        int rightMax = max(0, findMaxPathSum(node->right, maxi));

        maxi = max(maxi, leftMax + rightMax + node->val);

        return node->val + max(leftMax , rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
};