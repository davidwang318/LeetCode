// Very hard to handle the edge cases
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special cases:
        if (divisor == INT_MIN) return dividend == INT_MIN? 1 : 0;
        if (dividend == INT_MIN && abs(divisor) == 1) return divisor > 0? INT_MIN : INT_MAX;
        int sign = (!(dividend < 0) && !(divisor < 0)) || ((dividend < 0) && (divisor < 0));
        // Prevent overflow:
        bool carry = false;
        if (dividend == INT_MIN) {
            carry = true;
            dividend += 1;
        }
        // Change to positive sign
        if (dividend < 0) dividend = -dividend;
        if (divisor < 0) divisor = -divisor;
        // Driver function
        int res = 0;
        while (dividend >= divisor) {
            int tmp = divisor, resTmp = 1;
            while (tmp <= INT_MAX >> 1 && dividend >= (tmp << 1)) {
                tmp <<= 1;
                resTmp <<= 1;
            }
            res += resTmp;
            dividend -= tmp;
            if (carry) {
                dividend += 1;
                carry = false;
            }
        }
        return sign == 1 ? res : -res;
    }
};
