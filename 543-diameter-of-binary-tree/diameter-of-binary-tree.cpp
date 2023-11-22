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
    int diameterOfBinaryTree(TreeNode* root) {
        //just same as height of the binary tree with little bit changes

        int diameter = 0;
        findDiameter(root, diameter);
        return diameter;
    }

    int findDiameter(TreeNode *node, int &diameter) {
        if(node == NULL) 
            return 0;

        int leftHeight = findDiameter(node->left, diameter);
        int rightHeight = findDiameter(node->right, diameter);

        //having both side height now just find the maxi
        diameter = max(diameter, leftHeight + rightHeight);
        //this finds at each node the respective height
        return 1 + max(leftHeight, rightHeight);
    }
};