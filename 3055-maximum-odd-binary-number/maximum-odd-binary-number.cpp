class Solution {
public:
    int cntOne(string s) {
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }
    string maximumOddBinaryNumber(string s) {
        int oneCnt = cntOne(s);
        int zeroCnt = s.size()-oneCnt;
        string ans;
        for(int i=0; i<oneCnt-1;i++)
                ans += '1';
        
        for(int i=0; i<zeroCnt; i++) 
                ans += '0';
        
        ans += '1';
        return ans;
    }
};