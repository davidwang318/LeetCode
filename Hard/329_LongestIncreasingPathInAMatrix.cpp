// Top-down
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        dp = vector<vector<int>> (rows, vector<int> (cols, -1));
        int res = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;        
    }
private:
    int dfs(vector<vector<int>>& matrix, int rIdx, int cIdx){
        if (dp[rIdx][cIdx] != -1) return dp[rIdx][cIdx];
        dp[rIdx][cIdx] = 1;
        for (int i = 0; i < 4; i++){
            int trIdx = rIdx + dirs[i];
            int tcIdx = cIdx + dirs[i+1];
            if (trIdx < 0 || tcIdx < 0 || trIdx >= rows || tcIdx >= cols || matrix[trIdx][tcIdx] <= matrix[rIdx][cIdx])
                continue;
            dp[rIdx][cIdx] = max(dp[rIdx][cIdx], 1 + dfs(matrix, trIdx, tcIdx));
        }
        return dp[rIdx][cIdx];
    }
        
    int rows, cols;
    vector<vector<int>> dp;
    vector<int> dirs {0, 1, 0, -1, 0};
};

// Bottoms up
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        // Sort the matrix elements
        set<pair<int, pair<int, int>>> s;
        for (int i = 0; i < rows; i ++){
            for (int j = 0; j < cols; j ++){
                s.insert({matrix[i][j], {i, j}});
            }
        }
        // Bottoms up
        dp = vector<vector<int>> (rows, vector<int> (cols, 1));
        int res = 1;
        for (auto it = s.rbegin(); it != s.rend(); it++){
            int rIdx = it -> second.first;
            int cIdx = it -> second.second;
            for (int i = 0; i < 4; i++){
                int trIdx = rIdx + dirs[i];
                int tcIdx = cIdx + dirs[i+1];
                if (trIdx < 0 || tcIdx < 0 || trIdx >= rows || tcIdx >= cols || matrix[trIdx][tcIdx] <= matrix[rIdx][cIdx])
                    continue;
                dp[rIdx][cIdx] = max(dp[rIdx][cIdx], dp[trIdx][tcIdx] + 1);
            }
            res = max(res, dp[rIdx][cIdx]);
        }
        return res;
    }
        
    int rows, cols;
    vector<vector<int>> dp;
    vector<int> dirs {0, 1, 0, -1, 0};
};
