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
    bool isSymmetric(TreeNode* root) {
        	    //symmetric means the left subtree and right subtree is reflecting each other like a mirror
	    //should recursively solve the left using root,left,right and the right subtree as root,right,left
	    
	    return (root == NULL) || findSymmetric(root->left, root->right);
    }

    bool findSymmetric(TreeNode* left, TreeNode* right) {
        //base condition 
        if( !left || !right ) 
            return left == right;
        
        //failing condition to stop further checks
        if( left->val != right->val )
            return false;
        
        return findSymmetric(left->left, right->right) && findSymmetric(left->right, right->left);
    }
};