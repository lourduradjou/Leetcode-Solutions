class Solution {
private:
    bool isMatching(vector<int> &freq1, vector<int> &freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
    }

public:
    vector<int> findAnagrams(string str, string pattern) {
        int n1 = str.size();
        int n2 = pattern.size();
        vector<int> freqStr(26, 0);
        vector<int> freqPat(26, 0);
        vector<int> anagramStartIndices;
        int i = 0;

        for (auto ch: pattern)
            freqPat[ch - 'a']++;
        
        for (; i < n1; i++) {
            if (i < n2)
                freqStr[str[i] - 'a']++;
            else {
                if ( isMatching(freqStr, freqPat) )
                    anagramStartIndices.push_back(i - n2);
                
                freqStr[str[i - n2] - 'a']--;
                freqStr[str[i] - 'a']++;
            }
        }

        //finally check usually gets missed so lets it here
        if (isMatching(freqStr, freqPat))
            anagramStartIndices.push_back(i - n2);
            
        return anagramStartIndices;
    }
};