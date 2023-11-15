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
    void findPostOrder(TreeNode *node, vector<int> &ans) {
        if(node == NULL) {
            return;
        }

        //left + right + root
        findPostOrder(node->left, ans);
        findPostOrder(node->right, ans);
        ans.push_back(node->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        findPostOrder(root, ans);
        return ans;
    }
};