class Solution {
public:
    int maximum69Number (int num) {
        //convert to string
        string numStr = to_string(num);
        for (int i = 0; i < numStr.size(); i++) {
            if (numStr[i] == '6')
            {
                numStr[i] = '9';
                break;
            }
        }

        return stoi(numStr);
    }
};