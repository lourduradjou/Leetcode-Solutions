class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<long long, int> map1,map2;
        int size = arr.size();

        for(int i = 0; i<size; i++) 
        { 
            map1[arr[i]]++;           
        }

        for(auto ele: map1) 
            map2[ele.second]++;
            
        for(auto ele: map2) 
            if(ele.second > 1) 
                return false;
        
        return true;
    }
};