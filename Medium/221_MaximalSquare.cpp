// Time: 95.44%, Space: 41.86%
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), 0));
        int max_r = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') continue;
                if (i == 0 || j == 0) dp[i][j] = 1;
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                max_r = max(max_r, dp[i][j]);
            }
        }
        return max_r * max_r;
    }
};