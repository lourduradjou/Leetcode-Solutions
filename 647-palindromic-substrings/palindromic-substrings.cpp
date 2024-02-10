class Solution {
private:
    int isPalindrome(string s , int i , int j ) {
        while(i <= j) {
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                count += isPalindrome(s, i, j);//;
            }
        }
        return count;
    }
};