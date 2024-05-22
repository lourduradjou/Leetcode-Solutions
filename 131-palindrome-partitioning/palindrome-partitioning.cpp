class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        findPalindromicPartition(0,s,ds,ans);
        return ans;
    }

    void findPalindromicPartition(int index, string s, vector<string> &ds, 
    vector<vector<string>> &ans) {
        if(index >= s.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s,index,i)) {
                ds.push_back(s.substr(index, i - index + 1));
                findPalindromicPartition(i + 1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
};