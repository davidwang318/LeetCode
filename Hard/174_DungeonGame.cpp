// Great use of max( min()), need to review this.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int row = dungeon.size(), col = dungeon[0].size();
        std::vector<std::vector<int>> dp (row+1, std::vector<int>(col+1, INT_MAX));
        
        dp[row][col-1] = dp[row-1][col] = 1;
        for (int i = row-1; i >= 0; i--){
            for (int j = col-1; j >= 0; j--){
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

// We can do better just using 1D dynamic programming, because the knight can go only right and down.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int row = dungeon.size(), col = dungeon[0].size();
        std::vector<int> dp(col+1, INT_MAX);
        dp[col-1] = 1;
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};
