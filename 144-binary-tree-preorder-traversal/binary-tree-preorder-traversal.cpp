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
    void findPreOrder(TreeNode *node, vector<int> &ans) {
        if(node == NULL) 
            return;
        
        ans.push_back(node->val);

        findPreOrder(node->left, ans);

        findPreOrder(node->right, ans);


    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        findPreOrder(root, ans);
        return ans;
    }
};