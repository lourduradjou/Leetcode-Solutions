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
    int findBottomLeftValue(TreeNode* root) {
        //simple bfs is enough to find the left ..with little modification
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while( !q.empty() ) {
            TreeNode* node = q.front();
            q.pop();

            if (node != NULL) {
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }

            ans = node->val;
        }

        return ans;
    }
};