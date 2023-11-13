class Solution {
public:
    bool isVowel(char ch) {
        string str = "AEIOUaeiou";
        if(str.find(ch) != string::npos)
            return true;
        else 
            return false;
    }
    string reverseVowels(string s) {
        //store the vowels in a array reverse it and append
        vector<char> vowelList;
        for(char ch: s) {
            if(isVowel(ch))     
                vowelList.push_back(ch);
        }

        reverse(vowelList.begin(), vowelList.end());
        int i = 0;
        string ans = "";

        for(char ch: s) {
            if(isVowel(ch))
                ans += vowelList[i++];
            else 
                ans += ch;
        }

        return ans;
    }
};