class Solution {
public:  
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        //solving using minheap;
        priority_queue<int, vector<int>, greater<int>> freqMinHeap;
        unordered_map<int, int> mpp;
        for(auto it: arr) {
            mpp[it]++;
        }

        for(auto it: mpp) 
            freqMinHeap.push(it.second);

        int elementReduced = 0;
        while(!freqMinHeap.empty()) {
            elementReduced += freqMinHeap.top();
            if(elementReduced > k) return freqMinHeap.size();
            freqMinHeap.pop();
        }

        return 0;
    }
};



