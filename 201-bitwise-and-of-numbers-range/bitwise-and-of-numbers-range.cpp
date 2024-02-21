class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(right > left) 
            return rangeBitwiseAnd(left, right & (right - 1));
        return right;
    }
};