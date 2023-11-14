class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //create two vectors to store the first and last occurance of the letters 
        //then find the unique letters between them using set

        vector<int> minIndex(26,INT_MAX), maxIndex(26, INT_MIN);

        for(int i = 0; i < s.size(); i++) {
            int charIndex = s[i] - 'a';
            minIndex[charIndex] = min(minIndex[charIndex], i);
            maxIndex[charIndex] = max(maxIndex[charIndex], i);
        }

        int uniquePalindromeCount = 0;

        for(int i = 0; i < 26; i++) {
            if(minIndex[i] == INT_MAX || maxIndex[i] == INT_MIN) 
                continue;//because one parameter didnt exist so we cant find answer here

            unordered_set<char> uniqueCharsBetween;
            
            for(int j = minIndex[i] + 1; j < maxIndex[i]; j++) {
                uniqueCharsBetween.insert(s[j]);
            }

            uniquePalindromeCount += uniqueCharsBetween.size();

        }

        return uniquePalindromeCount;
    }
};