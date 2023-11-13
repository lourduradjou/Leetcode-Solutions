class Solution {
public:
    bool isVowel(char ch) {
        ch = toupper(ch);
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        else 
            return false;
    }
    string sortVowels(string s) {
        vector<char> vowelsList;
        for(char ch: s) {
            if(isVowel(ch))
                vowelsList.push_back(ch);
        }

        sort(vowelsList.begin(), vowelsList.end());
        string ans = "";
        int i = 0;

        for(char ch: s) {
            if(!isVowel(ch))
                ans += ch;
            else 
                ans += vowelsList[i++];
        }

        return ans;
    }
};