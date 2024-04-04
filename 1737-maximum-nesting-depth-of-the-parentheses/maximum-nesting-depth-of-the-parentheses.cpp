class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, openCnt = 0;
        for(auto ele: s) {
            if(ele == '(')
                openCnt++;
            else if(ele == ')')
                openCnt--;
            
            ans = max(ans, openCnt);
        }
        return ans;
    }
};