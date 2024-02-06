/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void findParents(TreeNode* root, unordered_map<TreeNode* , TreeNode* > &parent_track) {
        //we have to iterate the tree and mark it so lets use queue
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            TreeNode* curr = queue.front();
            queue.pop();

            if(curr->left) {
                parent_track[curr->left] = curr;
                queue.push(curr->left);
            }
            if(curr->right) {
                parent_track[curr->right] = curr;
                queue.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //first lets find the parents of each node
        unordered_map<TreeNode* , TreeNode* > parent_track;
        findParents(root, parent_track);

        //we need to visited ds to avoid looping and we need another queue to iterate
        queue<TreeNode*> queue;
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        queue.push(target);
        int distance = 0;

        while(!queue.empty()) {
            int size = queue.size();
            if(distance == k) break;
            distance++;

            for(int i = 0; i < size; i++) {
                TreeNode* curr = queue.front();
                queue.pop();
                if(curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    queue.push(curr->left);
                }
                if(curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    queue.push(curr->right);
                }
                if(parent_track[curr] && !visited[parent_track[curr]]) {
                    visited[parent_track[curr]] = true;
                    queue.push(parent_track[curr]);
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* curr = queue.front();
            queue.pop();
            result.push_back(curr->val);
        }

        return result;
    }
};