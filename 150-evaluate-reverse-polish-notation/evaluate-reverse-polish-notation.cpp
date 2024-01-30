class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                st.push(stoi(token));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            }
        }
        return st.top();
    }
};
