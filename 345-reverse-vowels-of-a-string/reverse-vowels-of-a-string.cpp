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
        //solving the problem using two pointer approach to reduce tc and sc 
        int start = 0, end = s.size()-1;
        string word = s;

        while(start < end) {
            while(start < end && !isVowel(word[start]) ) 
                start++;
            while(start < end && !isVowel(word[end]) ) 
                end--;
            
            swap(word[start], word[end]);
            //after swappend move to the next letter 
            start++; end--;
        }
        return word;
    }
};