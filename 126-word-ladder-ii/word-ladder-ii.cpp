class Solution {
private:
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    int size;
    string startWord;
private:
    void dfs(string word, vector<string>& seq) {
        if(word == startWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word]; //will give the steps
        for(int i = 0; i < size; i++) {
                char originalChar = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                        //we are getting new words which is one step lower than
                        //the current word so continue the dfs for that
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back();
                        //simple backtracking;
                    }
                }
                word[i] = originalChar;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        startWord = beginWord;
        mpp[beginWord] = 1;

        st.erase(beginWord);
        size = beginWord.size();

        while( !q.empty() ) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if(word == endWord) break;
            //we reached the endWord means that is deleted from the  st no
            //further search is required not possible also ha ha
            for(int i = 0; i < size; i++) {
                char originalChar = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.count(word) > 0) {
                        //we are getting new words so add it
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = originalChar;
            }
        }

        if(mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};








