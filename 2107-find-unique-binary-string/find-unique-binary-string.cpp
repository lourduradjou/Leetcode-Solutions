class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //using cantor's diagonal argument method just change the diagonal value and present it
        string result;

        for(int i = 0; i < nums.size(); i++) {
            char currChar = nums[i][i];
            result += (currChar == '0' ? '1' : '0');
        }

        return result;
    }
};