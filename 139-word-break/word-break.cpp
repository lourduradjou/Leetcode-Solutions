class Solution {
public:
    bool findSegmentedPattern(string s, set<string> &st, map<string, bool> &mp) {
        if(s.length() == 0) return true;
        if(mp.find(s) != mp.end()) return mp[s];
        //if already found in the dp return true;
        for(int i = 0; i < s.length(); i++) {
            string prefix = s.substr(0, i+1);
            string suffix = s.substr(i+1);

            if ( st.find(prefix) != st.end() && (st.find(suffix) != st.end() || findSegmentedPattern(suffix, st, mp)) ) 
                return mp[s] = true;
        }
        return mp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        
        map<string, bool> mp;
        return findSegmentedPattern(s, st, mp);
    }
};