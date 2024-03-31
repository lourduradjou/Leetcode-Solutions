class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int maxLength = 0, n = fruits.size();
        unordered_map<int, int> mpp;

        while (right < n) {
            mpp[fruits[right]]++; 
            if (mpp.size() > 2){
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);  
                left++;
            }

            if (mpp.size() <= 2)
                maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};