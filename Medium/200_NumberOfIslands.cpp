// First Attempt. Need to be more careful about the edge case.
// Time: 62.31%, Memory: 100.00%
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<vector<bool>> visit(row, vector<bool> (col, false)); 
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    res++;
                    isIsland(grid, visit, i, j);
                }
            }
        }
        return res;
    }
    
    void isIsland(vector<vector<char>>& grid, vector<vector<bool>>& visit, int r, int c){
        if(r < 0 || r == grid.size()) return;
        if(c < 0 || c == grid[0].size()) return;
        if(grid[r][c] == '0' || visit[r][c]) return;
        visit[r][c] = true;
        isIsland(grid, visit, r+1, c);
        isIsland(grid, visit, r-1, c);
        isIsland(grid, visit, r, c+1);
        isIsland(grid, visit, r, c-1);
        return;
    }
};
