class Solution {
public:
    void reverseString(string& st, int left, int right) {
        while (left < right) {
            swap(st[left], st[right]);
            left++;
            right--;
        }
    }
    string reversePrefix(string word, char ch) {
        int indexFound = -1;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                indexFound = i;
                break;
            }
        }

        if (indexFound != -1)
            reverseString(word, 0, indexFound);

        return word;
    }
};