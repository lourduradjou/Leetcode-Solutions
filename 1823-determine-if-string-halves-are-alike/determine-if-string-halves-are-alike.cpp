class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        int cntVowels1 = 0;
        int cntVowels2 = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i < n/2)
            {
                if(st.count(s[i])) cntVowels1++;
            }
            else
            {
                if(st.count(s[i])) cntVowels2++;
            }
        }
        //cout<<cntVowels<<endl;
        if(cntVowels1 == cntVowels2) return true;
        else return false;
    }
};