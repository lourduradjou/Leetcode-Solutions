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
    void inOrder(TreeNode* root, vector<int> &arr) {
        if(root == NULL) return;
        //left root and right is inorder;
        inOrder(root->left, arr);
        inOrder(root->right, arr);
        if(root->left == NULL && root->right == NULL)
            arr.push_back(root->val);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1 , leafValues2;
        inOrder(root1, leafValues1);
        inOrder(root2, leafValues2);

        int size = leafValues1.size();
        int size2 = leafValues2.size();


        if(size != size2) return false;
        for(int i = 0; i < size; i++) {
            if(leafValues1[i] != leafValues2[i])
                return false;
        }
        return true;
    }
};