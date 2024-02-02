class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string seq = "123456789";

        for(int len = 2; len <= seq.size(); len++) {
            for(int startIndex = 0; startIndex <= seq.size() - len; startIndex++) {
                string temp = seq.substr(startIndex, len);
                int possibleSeq = stoi(temp);

                if(possibleSeq >= low && possibleSeq <= high) 
                    ans.push_back(possibleSeq);
            }
        }
        return ans;
    }
};