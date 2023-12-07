#include<bits/stdc++.h>

class Solution {
public:
    string largestOddNumber(std::string num) {
        string ans = "";
        int i = num.size() - 1;
        while (i >= 0) {
            if (num[i] % 2 == 1) { // Compare with character '1'
                break;
            } else {
                i--;
            }
        }
        ans = num.substr(0, i + 1);
        return ans;
    }
};