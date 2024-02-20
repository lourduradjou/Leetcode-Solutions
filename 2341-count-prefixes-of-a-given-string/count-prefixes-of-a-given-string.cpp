class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        //brute force
        //generate all the prefixes and count it in the given vector and increase
        //the count of it
        vector<string> prefixes;
        string prefixWord = "";

        for(int i = 0; i < s.size(); i++) {
            prefixWord += s[i];
            prefixes.push_back(prefixWord);
        }

        //check and count
        int count = 0;
        for(auto word: prefixes){
            for(auto it: words) {
                if(word == it)
                    count++;
            }
        }

        return count;
    }
};










