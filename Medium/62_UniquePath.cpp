class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0){
                    dp[i][j] = 1; continue;
                }
                int up = i == 0? 0 : dp[i-1][j];
                int left = j == 0? 0 : dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp.back().back();
    }
};
