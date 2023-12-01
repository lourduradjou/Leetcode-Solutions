class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int ite_of_word1 = 0, ite_of_word2 = 0;
        int n1 = word1.size(), n2 = word2.size();

        while(i < n1 && j < n2) {
            string s1 = word1[i];
            string s2 = word2[j];
            int size_of_S1 = s1.size();
            int size_of_S2 = s2.size();

            while(ite_of_word1 < size_of_S1 && ite_of_word2 < size_of_S2) {
                if(s1[ite_of_word1] != s2[ite_of_word2])
                    return false;
                ite_of_word1++;
                ite_of_word2++;
            }
            if(ite_of_word1 == size_of_S1) {
                i++;
                ite_of_word1 = 0;
            }
            if(ite_of_word2 == size_of_S2) {
                j++;
                ite_of_word2 = 0;
            }
        }

        if(i != n1 || j != n2) 
            return false;
        
        return true;
    }
};