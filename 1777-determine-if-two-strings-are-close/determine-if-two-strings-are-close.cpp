class Solution {
private:
    bool findAnyMissingCharacter(string word1, string word2, set<char> &set1, set<char> &set2) {
        //first iterate over one string and then the other 
        for(char ch: word1) {
            if(set2.find(ch) == set2.end()) 
                return true;
        }
        for(char ch: word2) {
            if(set1.find(ch) == set1.end())
                return true;
        }
        return false;
    }
public:
    bool closeStrings(string word1, string word2) {
        //if there is mismatch of words that is anyone word is not having the other alphabet return false
        //also if size not matched 
        //also if the freq of freq not matched return false else return true;
        if(word1.size() != word2.size()) return false;
        vector<int> word1Count(26);
        vector<int> word2Count(26);
        set<char> set1;
        set<char> set2;
        unordered_map<int, int> freqCount;

        for(int i = 0; i < word1.size(); i++) {
            set1.insert(word1[i]);
            set2.insert(word2[i]);
            word1Count[word1[i] - 'a']++;
            word2Count[word2[i] - 'a']++;
        }

        if(findAnyMissingCharacter(word1, word2, set1, set2)) return false;
        for (int freq : word1Count)
            freqCount[freq]++;
        for (int freq : word2Count)
            freqCount[freq]--;

        for (pair<int, int> i : freqCount)
            if (i.second != 0)
                return false;

        return true;
    }
};