class Solution {
public:  
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for(auto it: arr) {
            mpp[it]++;
        }

        vector<int> freqVector;
        for(auto it: mpp) 
            freqVector.push_back(it.second);
        
        //now we have freq vector lets sort it and then reduce the element 
        //which are actually reducible
        sort(freqVector.begin(), freqVector.end());
        int elementReduced = 0;
        for(int i = 0; i < freqVector.size(); i++) {
            elementReduced += freqVector[i];
            if(elementReduced > k) return freqVector.size() - i;
        }

        return 0;
    }
};



