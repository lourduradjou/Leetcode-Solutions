class Solution {
public:
    int minLength(string s) {
        //okay brute force is to check for the "AB" and "CD" substring, is there if yes
        //remove them and check again , until there is no more substring 
        // with the combination they want.. 
        // this might take n^2 complexity as the time goes
        // the optimized approach is to use the stack , like in parenthesis problem...
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            
            if  ( !st.empty() &&  ( 
                 (st.top() == 'A' && s[i] == 'B')
                  || (st.top() == 'C' && s[i] == 'D') )
                )
                st.pop();
            else 
                st.push(s[i]);
        }
        
        return st.size();
    }
};