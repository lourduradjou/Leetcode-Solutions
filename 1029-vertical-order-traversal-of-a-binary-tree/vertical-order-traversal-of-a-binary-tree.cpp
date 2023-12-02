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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //just a map of map to store the vertical and its level
        //like x and y and its value using a multi set that will
        //store the values in ascending order
        map<int, map<int, multiset<int>> > nodes;
        queue<pair<TreeNode*, pair<int, int>>> listOfValues;
        listOfValues.push( {root, {0,0}} );
        //map will store the vertical and level and its values 
        //queue is used to traverse in level by level bfs
        //in queue will have node address and x and y
        while( !listOfValues.empty() ) {
            auto value = listOfValues.front();
            listOfValues.pop();
            TreeNode* node = value.first;

            int x = value.second.first, y = value.second.second;
            nodes[x][y].insert(node->val);
            if(node -> left) {
                listOfValues.push( {node->left, {x - 1, y + 1}} );
            } 
            if(node->right) {
                listOfValues.push( {node->right, {x + 1, y + 1}} );
            }
        }

        vector<vector<int>> ans;
        for(auto setOfValue: nodes) {
            //now i have the int , map<int, multiset> ;
            vector<int> temp;
            for(auto ele: setOfValue.second) {
                temp.insert(temp.end(), ele.second.begin(), ele.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};