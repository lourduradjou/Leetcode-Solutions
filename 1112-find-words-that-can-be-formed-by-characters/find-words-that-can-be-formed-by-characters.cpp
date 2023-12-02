class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};

        for(auto ch: chars) {
            freq[ch-'a']++;
        }

        int temp[26];
        int sum = 0;

        for(int i = 0; i < words.size(); i++) {

            for(int ite = 0; ite < 26; ite++)
                temp[ite] = freq[ite];

            for(int j = 0; j < words[i].size(); j++) {
                temp[words[i][j] - 'a']--;
                if(temp[words[i][j] - 'a'] < 0) {
                    break;
                }

                if(j == words[i].size() - 1) {
                    sum += words[i].size();
                }
            //sum += words[i].size();
            }

        
        }
    return sum;
    }
};