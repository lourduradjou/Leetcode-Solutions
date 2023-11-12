class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        //two pointer approach to solve the problem in one iteration
        int i = 0;
        int j = 0;
        int n1 = word1.size();
        int n2 = word2.size();
        string ans;
        
        while(i < n1 && j < n2) {
            ans += word1[i++];
            ans += word2[j++];
        }

        while(i < n1) {
            ans += word1[i++];
        }

        while(j < n2) {
            ans += word2[j++];
        }

        return ans;
    }
};