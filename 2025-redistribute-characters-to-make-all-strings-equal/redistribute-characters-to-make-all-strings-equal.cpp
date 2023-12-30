class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //use a vector to count the number of each chars in each string
        //and then just compare whether it has a count of n 
        int n = words.size();
        if(n == 1)
            return true;
        unordered_map<char,int> freq;
        for(string& word : words) {
            for(char& ch: word) {
                freq[ch]++;
            }
        }

        for(auto it: freq) {
            if(it.second % n != 0)
                return false;
        }

        return true;
    }
};