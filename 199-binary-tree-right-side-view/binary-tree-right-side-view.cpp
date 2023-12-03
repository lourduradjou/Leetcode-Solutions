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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        findRightSideView(0, root, ans);
        return ans;
    }

    void findRightSideView(int level, TreeNode* node, vector<int> &ans) {
        if(!node) return;
        
        if(ans.size() == level)
            ans.push_back(node->val);
        
        findRightSideView(level + 1, node->right, ans);
        findRightSideView(level + 1, node->left, ans);
    }
};

