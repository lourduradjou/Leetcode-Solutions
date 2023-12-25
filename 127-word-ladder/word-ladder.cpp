
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //this problem is very easy just take each word and change each letter
        //to different alphabets and in the meanwhile use a bfs to get the level 
        //at each very are finding the end word. Here instead of vis array we are
        //using set data structure and deleting whenever, the word has been taken.
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while( !q.empty() ) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == endWord)    
                return steps;

            for(int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) // it found so push into the q
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = originalChar;
            }

        }

        return 0;
    }
};