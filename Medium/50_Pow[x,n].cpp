class Solution {
public:
    double myPow(double x, int n) {
        double res = helper(x, abs(n));
        return n > 0? res : 1 / res;
    }
    double helper(double x, int n) {
        if (n == 0) return 1;
        double half = helper(x, n/2);
        return (n % 2) ? x * half * half : half * half;
    }
};
