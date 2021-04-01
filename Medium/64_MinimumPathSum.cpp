// Revisit 20210301
// Time: 99.37%, Space: 51.42%
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rLen = grid.size(), cLen = grid[0].size();
        vector<vector<int>> dp (rLen, vector<int>(cLen, 0));
        for (int r = 0; r < rLen; ++r) {
            for (int c = 0; c < cLen; ++c) {
                if (r == 0 && c == 0) dp[r][c] = grid[r][c];
                else if (r == 0) dp[r][c] = dp[r][c-1] + grid[r][c];
                else if (c == 0) dp[r][c] = dp[r-1][c] + grid[r][c];
                else dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + grid[r][c];
            }
        }
        return dp.back().back();
    }
};