class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        
        // If the length of s is odd, it can never be valid
        if (n % 2 != 0) return false;
        
        // First pass (left to right): Ensuring balanced parentheses
        int openCount = 0;
        for (int i = 0; i < n; ++i) {
            // If it's locked and '(' then increment openCount
            if (locked[i] == '1') {
                if (s[i] == '(') openCount++;
                else openCount--;
            } 
            // If it's unlocked, assume we can use it as an open parenthesis
            else {
                openCount++;
            }
            
            // If at any point we have more closing parentheses than opening ones, it's invalid
            if (openCount < 0) return false;
        }
        
        // Second pass (right to left): Ensuring balanced parentheses again
        int closeCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')') closeCount++;
                else closeCount--;
            }
            // If it's unlocked, assume we can use it as a closing parenthesis
            else {
                closeCount++;
            }

            // If at any point we have more opening parentheses than closing ones, it's invalid
            if (closeCount < 0) return false;
        }

        return true;
    }
};
