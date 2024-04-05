class Solution {

private:
    bool check(stack<char> &st, string &s, int i) {
        return (!st.empty() && abs(st.top() - s[i]) == 32);
    }
public:
    string makeGood(string s) {
        if (s.size() == 0) return s;

        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if ( check(st, s, i) )
                st.pop();
            else
                st.push(s[i]);
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
