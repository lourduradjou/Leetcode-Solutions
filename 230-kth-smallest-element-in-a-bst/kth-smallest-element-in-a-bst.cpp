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
    TreeNode* solve(TreeNode* root, int& k) {
        if (root == NULL)
            return NULL;
        
        TreeNode* left = solve(root->left, k);

        if (left != NULL)
            return left; //return the node when it is not null no need to check further here
        
        if (--k == 0)
            return root;
        //cout<<root->val<<" "<<k<<endl;
        return solve(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = solve(root, k);
        return (ans == NULL) ? -1 : ans->val;
    }
};