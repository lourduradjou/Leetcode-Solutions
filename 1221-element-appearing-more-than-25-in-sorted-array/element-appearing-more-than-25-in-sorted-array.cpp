class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        int quantity = size / 4;
        int count = 1;
        //initially we are taking count as 1 cause we are choosing an element here
        int ele = arr[0];

        for(int i = 1; i < size; i++) {
            if(ele == arr[i]) 
                count++;
            else
                count = 1;
            
            if(count > quantity)
                return arr[i];
            
            //after this update the ele value
            ele = arr[i];
        }

        return ele;
    }
};