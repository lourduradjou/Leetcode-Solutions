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
    unordered_map<int, vector<int>> tree;
    void dfs(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return;
        }

        if(root->left) {
            tree[root->val].push_back(root->left->val);
            tree[root->left->val].push_back(root->val);
            dfs(root->left);
        }

        if(root->right) {
            tree[root->val].push_back(root->right->val);
            tree[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root); //create the graph 
        queue<pair<int,int>> q;
        int time = 0;
        q.push({start, 0});
        set<int> vis;
        vis.insert(start);
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int node = front.first;
            int currTime = front.second;
            time = max(time, currTime);

            for(auto &adj: tree[node]) {
                if(vis.find(adj) == vis.end()) {
                    vis.insert(adj);
                    q.push({adj, currTime + 1});
                }
            }
        }
        return time;
    }
};