class Solution {
private:
    int maxDifference = 0;
    void findMaxDifferences(TreeNode* currentNode,int minValue, int maxValue) {
        if(currentNode) {
            minValue = min(minValue, currentNode->val);
            maxValue = max(maxValue, currentNode->val);
            maxDifference = max(maxDifference, maxValue - minValue);
            findMaxDifferences(currentNode->left, minValue, maxValue);
            findMaxDifferences(currentNode->right, minValue, maxValue);
        }
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        findMaxDifferences(root, root->val, root->val);
        return maxDifference;
    }

};