class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int l = 0, r = x;
        while(l < r) {
            int m = l + (r - l) / 2;
            int res = x / m;
            if (res == m) return m;
            else if (res < m) r = m - 1;
            else l = m + 1;
        }
        return l * l > x ? l - 1 : l;
    }
};