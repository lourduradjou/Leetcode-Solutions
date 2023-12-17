class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        //simple median makes sense and mean will take lot of cost
        //[1, 1, 1000] check with this example of go to discussion section
        //find the closer value of median by incrementin and decrementing
        //find the respective values and look for minimum in that
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int num1 = inc(nums[n/2]);
        int num2 = dec(nums[n/2]);

        return  min(findCost(num1, nums) , findCost(num2, nums));
    }

    bool isPalindrome(int n) {
        string s = to_string(n);
        int left = 0, right = s.size()-1;
        while(left <= right)
            if( s[left++] != s[right--] ) 
                return false;
        
        return true;
    }

    int inc(int num) {
        while( !isPalindrome(num) )
            num++;
        return num;
    }
    int dec(int num) {
        while( !isPalindrome(num) )
            num--;
        return num;
    }
    long long findCost(int palindromeNum, vector<int> nums) {
        long long ans = 0;
        for(int value: nums) {
            ans += abs(value - palindromeNum);
        }
        return ans;
    }
};