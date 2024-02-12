class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majEle = 0;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                cnt = 1;
                majEle = nums[i];
            }
            else if(nums[i] == majEle) 
                cnt++;
            else 
                cnt--;
        }
        return majEle;
    }
};