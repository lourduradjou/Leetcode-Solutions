class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0) return 0;
        if (__builtin_clz(left) != __builtin_clz(right))
            return 0;
        while(right > left) {
            right = right & (right - 1);
        }
        return right;
    }
};