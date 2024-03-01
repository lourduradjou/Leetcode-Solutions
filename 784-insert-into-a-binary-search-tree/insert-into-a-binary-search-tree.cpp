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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* newNode = (TreeNode*) new TreeNode(val);
        if (root == NULL) return newNode;

        while (curr!=NULL) {
            if (val < curr->val && curr->left == NULL) {
                curr->left = newNode;
                return root;
            }
            else if (val > curr->val && curr->right == NULL){
                curr->right = newNode;
                return root;
            }

            if (val < curr->val)
                curr = curr->left;
            else 
                curr = curr->right;
        }

        return root;
    }
};