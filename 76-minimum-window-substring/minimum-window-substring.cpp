class Solution {
public:
    string minWindow(string s, string t) {
        //easy approach using the frequency of the string t, if forgot revise it , pretty easy.
        unordered_map<char, int> tmap;
        for(auto ch: t) tmap[ch]++;
        int i = 0, j = 0, counter = t.size();
        int minStart = 0, minLength = INT_MAX;
        int n = s.size();

        while( j < n ) {
            //if j th character is having some frequency greater than 0.
            if( tmap[s[j]] > 0 ) {
                counter--;
            }
            tmap[s[j]]--;
            j++;

            //this loop is to shrik the starting indexing to reduce the count and get smallest window
            while(counter == 0) {
                if(j - i < minLength) {
                    minStart = i;
                    minLength = j - i;
                }
                tmap[s[i]]++;
                if(tmap[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }
        return (minLength == INT_MAX) ? "": s.substr(minStart, minLength);
    }
};