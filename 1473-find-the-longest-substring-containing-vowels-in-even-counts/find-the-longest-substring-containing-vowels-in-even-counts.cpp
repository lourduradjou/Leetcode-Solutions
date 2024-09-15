class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0, maxLength = 0;
        unordered_map<int,int> map;
        map[0] = -1; //initial adjustment to increment one in the maxlength line below at 20

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);
            
            // cout<<"Letter: "<<s[i]<<endl;
            // cout<<"Mask: "<<bitset<5>(mask)<<endl;

            if (map.find(mask) != map.end()) {
                maxLength = max(maxLength, i - map[mask]);
                // cout<<"Inside maxlength "<<maxLength<<endl;
            }else {
                map[mask] = i;
                // cout<<"Inside else "<<map[mask];
            }
            cout<<endl;

        }

        return maxLength;
    }
};