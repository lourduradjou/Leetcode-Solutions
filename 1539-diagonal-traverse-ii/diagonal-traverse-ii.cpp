class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        queue<pair<int,int>> que;

        que.push({0,0});

        while( !que.empty() ) {
            auto pair = que.front();
             //getting the left most element;
            //the check to go to the next line with col = 0;
            que.pop();

            int row = pair.first;
            int col = pair.second;

            ans.push_back(nums[row][col]);

            if(col == 0 && row + 1 < nums.size())
                que.push({row+1, col});
            
            //then check for right side check the rightboundary of that row also
            if(col + 1 < nums[row].size()) 
                que.push({row, col+1});
            
        }

        return ans;         
    }
};