class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        rowLen = triangle.size();
        vector<vector<int>> dp (rowLen, vector<int> (rowLen, -1));
        return dfs(triangle, dp, 0, 0);
    }
private:
    int dfs(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row, int col) {
        if (row >= rowLen) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        dp[row][col] = min(dfs(triangle, dp, row+1, col), dfs(triangle, dp, row+1, col+1))
                     + triangle[row][col];
        return dp[row][col];
    }
    int rowLen;
};
