
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        //at even level , node values should be increasing and it gotta be odd
        //at odd level , node values should be decreasing and it gota be even
        //simple bfs from left to right and at each level check the condition
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        //for root 
        if (root->val % 2 == 0)
            return false;

        while ( !q.empty() ) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            //checking the current node status
            if (level % 2 == 1 && node->val % 2 == 1) return false;
            if (level % 2 == 0 && node->val % 2 == 0) return false;

            if (node->left) 
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});

            if (level % 2 == 0)
            {
                while (!q.empty() && q.front().second % 2 == 0) {
                    TreeNode* nextNode = q.front().first;
                    if (nextNode->val <= node->val || nextNode->val % 2 == 0)
                        return false;

                    if (nextNode->left)
                        q.push({nextNode->left, level+1});
                    if (nextNode->right)
                        q.push({nextNode->right, level + 1});
                    
                    node = nextNode;
                    q.pop();
                }
            } else {
                while (!q.empty() && q.front().second % 2 == 1) {
                    TreeNode* nextNode = q.front().first;
                    if (nextNode->val >= node->val || nextNode->val % 2 == 1)
                        return false;

                    if (nextNode->left)
                        q.push({nextNode->left, level+1});
                    if (nextNode->right)
                        q.push({nextNode->right, level + 1});

                    node = nextNode;
                    q.pop();
                }
            }
        }
        return true;
    }
};