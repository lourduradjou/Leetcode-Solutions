class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //now with stack
        //the complexity of tc: O(2n) quite better than previous one without stack almost same only
        //first pass
        //simpply count the parenthesis if right ')' goes more than left
        //just reduce and move on this maintains that no pairs with more right parenthesis exists
        //example )))aaa here each time the ))) gets ignored finally the last letters gets added
        //second loop avoid the extra leftparethesis if any and add the string (answer)
        int leftParenthesis = 0;
        int rightParenthesis = 0;

        stack<char> st;

        for (char ch: s) {
            if (ch == '(')
                leftParenthesis++;
            if (ch == ')')
                rightParenthesis++;
            
            if (rightParenthesis > leftParenthesis)
                rightParenthesis--;
            else
                st.push(ch);
        }

        string answer = "";
        while (!st.empty()) {
            char currChar = st.top();
            st.pop();
            if (leftParenthesis > rightParenthesis && currChar == '(')
                leftParenthesis--;
            else
                answer += currChar;
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};