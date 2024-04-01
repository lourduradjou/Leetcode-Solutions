class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size()-1;
        int cnt = 0;
        while(right >= 0 && s[right] == ' ') right--;
        while(right >= 0 && s[right] != ' ') {cnt++; right--;}
        return cnt;
    }
};