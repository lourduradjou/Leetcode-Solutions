class Solution {
public:
    string minWindow(string s, string t) {
        //okay, using hash vector and sliding window is problems is pretty easy
        if (s.empty() || t.empty())
            return "";
        
        int l = 0, r = 0, minLength = INT_MAX, cnt = 0;
        int n = s.size(), m = t.size(), startIndex = -1;
        vector<int> hash(256, 0);

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0) // this is from t string
                cnt++;
            //reduce that count as that string is in the window now
            hash[s[r]]--;

            while (cnt == m) {
                //if true all the letters from t -> in s is true
                //including duplicates
                if ( (r - l + 1) < minLength ) {
                    minLength = (r - l + 1);
                    startIndex = l;
                }
                //we got a good pair so lets shrink the window 
                hash[s[l]]++;
                if (hash[s[l]] > 0) //this is from t so as we removed it from the windows reduce the cnt
                    cnt--;
                l++;
            }

            r++;
        }

        return (startIndex == -1) ? "" : s.substr(startIndex, minLength);
    }
};