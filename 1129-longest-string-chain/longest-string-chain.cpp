class Solution {
private: 
    static bool comp(string &st, string &s2) {
        return st.size() < s2.size();
    }

    bool checkPossible(string &str1, string &str2) {
        if (str1.size() != str2.size() + 1) return false; //we want the str2 to be only one less than the next string

        int first = 0, second = 0;
        while (first < str1.size()) {
            if (str1[first] == str2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        if (first == str1.size() && second == str2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        // vector<int> hash(n);
        int maxi = 1;
        // int lastIndex = 0;

        sort(words.begin(), words.end(), comp);

        for (int i = 1; i < n; i++) {
            //hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if ( checkPossible(words[i], words[prev]) && dp[i] < dp[prev] + 1 ) {
                    dp[i] = 1 + dp[prev]; //take the largest value
                    // hash[i] = prev; //mark to print, if needed
                }
            }

            //markdown the last index to trace back
            if (dp[i] > maxi) {
                maxi = dp[i];
                // lastIndex = i;
            }
        }

        return maxi;

        // vector<int> temp;
        // temp.push_back(words[lastIndex]);
        // while (hash[lastIndex] != lastIndex) {
        //     temp.push_back(words[hash[lastIndex]]);
        //     lastIndex = hash[lastIndex];
        // }

        // reverse(temp.begin(), temp.end());
        // return temp;
    }
};