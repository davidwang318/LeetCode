class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b & INT_MAX) << 1;
        return getSum(sum, carry);
    }
};
