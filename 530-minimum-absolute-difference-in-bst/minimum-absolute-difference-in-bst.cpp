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
    void inorder_traversel(TreeNode* root, vector<int> &arr) {
        if(root == NULL) return;
        inorder_traversel(root->left, arr);
        arr.push_back(root->val);
        inorder_traversel(root->right, arr);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        //binary search tree will give sorted values in inorder traversal
        vector<int> arr;
        inorder_traversel(root, arr);
        int n = arr.size();
        int minValue = INT_MAX;

        for(int i = 0; i < n-1; i++) {
            minValue = min(minValue, arr[i+1] - arr[i]);
        }

        return minValue;
    }
};