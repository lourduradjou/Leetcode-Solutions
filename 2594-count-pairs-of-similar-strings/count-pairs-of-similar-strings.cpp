class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            unordered_set<char> st1;
            for(char ch: words[i]) st1.insert(ch);

            for (int j = i+1; j < words.size(); j++) {
                unordered_set<char> st2;
                int flag = 1;
                for(char ch: words[j]) {
                    st2.insert(ch);
                    if (st1.find(ch) == st1.end()) {
                        flag = 0;
                        break;
                    }
                }
                  
                if (st1.size() == st2.size() && flag) 
                    cnt += flag;
            }
        }

        return cnt;
    }
};