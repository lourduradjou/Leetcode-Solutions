class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //using seperate arrays for positive and negative values
        vector<int> pos, neg, ans;
        for(auto ele: nums) {
            if(ele > 0) 
                pos.push_back(ele);
            else 
                neg.push_back(ele);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) //push the positive
                ans.push_back(pos[i / 2]);
            else 
                ans.push_back(neg[i / 2]);
        }

        return ans;
    }
};