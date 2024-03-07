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
    int find_left_height(TreeNode* root) {
        int height = 0;
        while (root)
        {
            height++;
            root = (root->left);
        }
        return height;
    }

    int find_right_height(TreeNode* root) {
        int height = 0;
        while (root)
        {
            height++;
            root = (root->right);
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) 
            return 0;
    
        int left_height = find_left_height(root);
        int right_height = find_right_height(root);
        //cout<<left_height<<" "<<right_height<<endl;

        if (left_height == right_height) 
            return (1 << left_height) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};