// Math trick problem
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp (n+1, 0);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            int h = sqrt(i);
            for (int j = 2; j <= h; ++j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i/j];
                }
            }
        }
        return dp.back();
    }
};