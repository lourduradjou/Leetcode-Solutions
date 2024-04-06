class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //using a double loop we can easily marks the unwanted stuffs and finally
        //iterate to find the answer string intuitive approach
        // tc: O(3n)
        //first iteration to find the number of open parenthesis and its corresponding matches 
        //of closing parenthesis

        int openParenthesisCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                openParenthesisCount++;
            else if (s[i] == ')') {
                //check for parenthesis count here , open count is 0 means we dont have matching pair
                if (openParenthesisCount == 0)
                    s[i] = '*';
                else
                    openParenthesisCount--;
                //a pair exists so reduce the count of open parenthesis in else part
            }
        }

        //second pass to remaining open parenthesis , leftover parenthesis 
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(' && openParenthesisCount > 0)
            {
                //means there exists some unwanted count of open parenthesis
                s[i] = '*';
                openParenthesisCount--;
            }
        }

        string ans = "";
        for (auto it: s) 
            if (it != '*')
                ans += it;

        return ans;
    }
};
