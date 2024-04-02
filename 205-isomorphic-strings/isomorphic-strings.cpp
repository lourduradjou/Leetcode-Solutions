class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int strAssigned[256] = {0};
        int used[256] = {0};

        for(int i=0; i < s.size(); i++) {
            if(strAssigned[s[i]] == 0 && used[t[i]] == 0) {
                strAssigned[s[i]] = t[i]; //marking that s[i] is assinged for t[i] here
                used[t[i]] = 1; //marking that t[i] is used so it can't be used for other values 
                //think of example like
                //s = "abdc"
                //t = "xyxy"
            }
        }

        for(int i=0; i < s.size(); i++) {
            if(strAssigned[s[i]] != t[i]) //it is not matching return false
                return false;
        }
        return true;
    }
};