class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //use a hashmap of string and flag kinda to thing to get the destination 
        //from where no outgoing.
        unordered_map<string, int> mpp;

        for(auto path : paths) {
            string city1 = path[0];
            string city2 = path[1];

            mpp[city1] = 1;
            if(mpp.find(city2) == mpp.end()) {
                mpp[city2] = 0;
            }
            else {
                mpp[city2] = 1;
            }
        }

        string ans = "";
        for(auto it: mpp) {
            if(it.second == 0) {
                ans = it.first;
            }
        }

        return ans;
    }
};