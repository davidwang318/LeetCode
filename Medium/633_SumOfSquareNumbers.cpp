class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = pow(c, 0.5);
        while (left <= right) {
            int l = left*left, r = right*right;
            if (l > INT_MAX - r) {
                --right; continue;
            }
            int s = l + r;
            if (s == c) return true;
            else if (s > c) right--;
            else left++;
        }
        return false;
        
    }
};