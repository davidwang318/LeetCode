// DFS solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        rLen = obstacleGrid.size();
        cLen = obstacleGrid[0].size();
        dp = vector<vector<int>> (rLen, vector<int> (cLen, -1));
        dp.back().back() = 1;
        return dfs(obstacleGrid, 0, 0);
    }
private:
    int dfs(vector<vector<int>>& grid, int rIdx, int cIdx){
        if (rIdx < 0 || cIdx < 0 || rIdx >= rLen || cIdx >= cLen || grid[rIdx][cIdx]) return 0;
        if (dp[rIdx][cIdx] != -1) return dp[rIdx][cIdx];
        dp[rIdx][cIdx] = dfs(grid, rIdx + 1, cIdx) + dfs(grid, rIdx, cIdx + 1);
        return dp[rIdx][cIdx];
    }
    int rLen = 0, cLen = 0;
    vector<vector<int>> dp;
};
// Bottoms up solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
        int rLen = obstacleGrid.size();
        int cLen = obstacleGrid[0].size();
        vector<int> dp (cLen, 0);
        dp[0] = 1;
        for (int i = 0; i < rLen; i ++){
            for (int j = 0; j < cLen; j ++){
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j]) {dp[j] = 0; continue;}
                int left = (j) ? dp[j-1] : 0;
                int up = (i) ? dp[j] : 0;
                dp[j] = left + up;
            }
        }
        return dp.back();
    }
};
