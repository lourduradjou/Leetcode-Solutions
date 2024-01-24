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
    int pseudo_count(TreeNode* node, vector<int> &countArray, int &count) {
        if(node == NULL) return 0;
        countArray[node->val]++;

        pseudo_count(node->left, countArray, count);
        pseudo_count(node->right, countArray, count);

        if(node->left == NULL && node->right == NULL) {
            //it is  leaf node
            int oddOccurances = 0;
            for(int i = 1; i <= 9; i++) {
                if(countArray[i] % 2 == 1) //it is an odd count
                    oddOccurances++;
            }

            if(oddOccurances <= 1) // it is a valid palindrome
                count++;
        }

        countArray[node->val]--;
        return count;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> countArray(10, 0);
        int count = 0;
        pseudo_count(root, countArray, count);

        return count;
    }
};