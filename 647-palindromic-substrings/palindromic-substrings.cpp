class Solution {
private:
    int palindrome(string s, int i , int j ) {
        int count = 0;
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
            count++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        //another method to solve it 
        //going from center to outwords 
        //for both even and odd approaches of palindromes
        int count = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            int oddCount = palindrome(s, i , i);
            int evenCount = palindrome(s, i, i+1);
            count += (oddCount + evenCount);
        }
        return count;
    }
};