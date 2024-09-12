class Solution {
public:
    void setFreq(string word, vector<int> &freq) {

        for (char ch: word) {
            freq[ch-'a']++;
        }
    }
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            vector<int> freq(26, 0);
            setFreq(words[i], freq);

            for (int j = i+1; j < words.size(); j++) {
                int flag = 1;
                for(char ch: words[j]) {
                    if (freq[ch - 'a'] == 0) {
                        flag = 0;
                        break;
                    }
                }
                unordered_set<char> st1, st2;
                for(char ch: words[i]) st1.insert(ch);
                for(char ch: words[j]) st2.insert(ch);
                if (st1.size() == st2.size() && flag) 
                    cnt += flag;
        
                // if (flag) {
                //     cout<<words[i]<<" "<<words[j]<<endl;
                // }
            }
        }

        return cnt;
    }
};