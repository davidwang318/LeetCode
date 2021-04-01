// Revisit at 20210307, still can't solve it at the first glance.
// Much intuitive solution
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (n + 1, 0);
        return numSquares(n, dp);
    }
private:
    int numSquares(int n, vector<int>& dp) {
        if (n == 0 || dp[n] != 0) return dp[n];
        int res = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            res = min(res, numSquares(n - i * i, dp) + 1);
        }
        return dp[n] = res;
    }
};
// So hard...
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
// My solution, more intuitive in my opinion
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp.back();
    }
};
