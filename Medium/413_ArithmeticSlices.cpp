class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int total = 0, pre = 0;
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                ++pre;
                total += pre;
            }
            else
                pre = 0;
        }
        return total;
    }
};