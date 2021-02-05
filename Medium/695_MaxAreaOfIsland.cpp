/* Only need visited, not visiting.
why?
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!isVisited(grid, i, j)) res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
private:
    vector<int> directions {1, 0, -1, 0, 1};
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
        if (grid[r][c] == 0 || isVisited(grid, r, c)) return 0;
        markVisited(grid, r, c);
        int curSize = 1;
        for (int i = 0; i < 4; ++i) {
            curSize += dfs(grid, r+directions[i], c+directions[i+1]);
        }
        return curSize;
    }
    
    
    void markVisited(vector<vector<int>>& grid, int r, int c) {
        grid[r][c] |= 2;
        return;
    }
    bool isVisited(vector<vector<int>>& grid, int r, int c) {
        return grid[r][c] & 2;
    }
};