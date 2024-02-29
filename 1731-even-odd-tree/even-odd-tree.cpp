class Solution {
private:
    bool checkEvenLevel(TreeNode* frontNode, int prev) {
        return frontNode->val %2==0 || frontNode->val <=  prev;
    }

    bool checkOddLevel(TreeNode* frontNode,int prev) {
        return frontNode->val %2!=0  || frontNode->val  >= prev;
    }

    void insertNode(TreeNode* node, queue<TreeNode*>& q) {
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->val % 2 == 0) return false;

        queue<TreeNode*> q;
        q.push(root);
        bool isEvenLevel = true;

        while (!q.empty()) {
            int size = q.size();
            int prev = isEvenLevel ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();

                if (isEvenLevel) {
                    if (checkEvenLevel(frontNode, prev))
                        return false;
                }
                else {
                    if (checkOddLevel(frontNode, prev))
                        return false;
                }

                insertNode(frontNode,  q);
                prev = frontNode->val;
            }
            isEvenLevel = !isEvenLevel;
        }
        return true;
    }
};