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
    vector<int> treeValues;
    void findKthNumber(TreeNode* root) {
        if (root == NULL) return;
        findKthNumber(root->left);
        treeValues.push_back(root->val);
        return findKthNumber(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        findKthNumber(root);
        return treeValues[k-1];
    }
};