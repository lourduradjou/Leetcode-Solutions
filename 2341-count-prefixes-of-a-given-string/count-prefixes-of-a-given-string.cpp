class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        //to reduce the tc , we iterate our the given string itself
        //this approach is quiet nice ..
        int count = 0;

        for (auto word: words) {
            int j = 0;
            for (j = 0; j < word.size(); j++) {
                if(word[j] != s[j])
                    break;
            }
            if (j == word.size())
                count++;
        }
        return count;
    }
};










