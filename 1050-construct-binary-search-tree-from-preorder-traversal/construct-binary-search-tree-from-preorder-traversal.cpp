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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildTree(preorder, i, INT_MAX);
    }

    TreeNode* buildTree(vector<int>& preOrder, int& i, int upperLimit) {
        if (i == preOrder.size() || preOrder[i] > upperLimit)
            return NULL;

        TreeNode* root = new TreeNode(preOrder[i++]);
        root->left = buildTree(preOrder, i, root->val);
        root->right = buildTree(preOrder, i, upperLimit);
        return root;
    }
};