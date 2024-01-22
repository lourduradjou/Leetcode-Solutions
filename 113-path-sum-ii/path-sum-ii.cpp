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
    void dfs(TreeNode *root, int sum, int curr, vector<int> temp, vector<vector<int>> &ans) {
        if(root == NULL) return;
        curr += root->val;
        temp.push_back(root->val);
        
        if(curr == sum && root->left == NULL && root->right == NULL) 
            ans.push_back(temp);
        dfs(root->left, sum, curr, temp, ans);
        dfs(root->right, sum, curr, temp, ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, targetSum, 0, temp, ans);
        return ans;
    }
};