class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
        rLen = matrix.size();
        cLen = matrix[0].size();
        vector<vector<bool>> pacific(rLen, vector<bool> (cLen, false));
        vector<vector<bool>> atlantic(rLen, vector<bool> (cLen, false));
        vector<vector<int>> res;
        for (int r = 0; r < rLen; ++r) {
            dfs(matrix, pacific, atlantic, res, r, 0);
            dfs(matrix, atlantic, pacific, res, r, cLen-1);
        }
        for (int c = 0; c < cLen; ++c) {
            dfs(matrix, pacific, atlantic, res, 0, c);
            dfs(matrix, atlantic, pacific, res, rLen-1, c);
        }
        return res;        
    }
private:
    vector<int> dirs {-1, 0, 1, 0, -1};
    int rLen, cLen;
    void dfs(vector<vector<int>>& m, vector<vector<bool>>& visited, vector<vector<bool>>& other, vector<vector<int>>& res, int r, int c) {
        if (visited[r][c]) return;
        visited[r][c] = true;
        if (visited[r][c] && other[r][c]) res.push_back({r, c});
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i], nc = c + dirs[i+1];
            if (isValid(nr, nc) && m[r][c] <= m[nr][nc]) 
                dfs(m, visited, other, res, nr, nc);
        }
        return;
    }
    bool isValid(int r, int c) {
        return !(c < 0 || c >= cLen || r < 0 || r >= rLen);
    }
};