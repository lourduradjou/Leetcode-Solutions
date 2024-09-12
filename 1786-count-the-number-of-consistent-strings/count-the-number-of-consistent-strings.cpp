class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0};
        for(char ch: allowed) {
            arr[ch - 'a'] = 1;
        }

        int cnt = 0;

        for (string& word: words) {
            int flag = 1;
            
            for (char ch: word) {
                if (arr[ch - 'a'] == 0) {
                    flag = 0;
                    break;
                }
            }

            cnt += flag;
        }

        return cnt;
    }
};