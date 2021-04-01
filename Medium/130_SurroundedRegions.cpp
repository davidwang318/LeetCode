// Best solution
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        rLen = board.size();
        cLen = board[0].size();
        for (int r = 0; r < rLen; ++r) {
            dfsTraversal(board, r, 0);
            dfsTraversal(board, r, cLen-1);
        }
        for (int c = 0; c < cLen; ++c) {
            dfsTraversal(board, 0, c);
            dfsTraversal(board, rLen-1, c);
        }
        
        for (int r = 0; r < rLen; ++r) {
            for (int c = 0; c < cLen; ++c) {
                if (board[r][c] == '!') board[r][c] = 'O';
                else if (board[r][c] == 'O') board[r][c] = 'X';
            }
        }
        return;
    }
private:
    void dfsTraversal(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r == rLen || c == cLen || 
            board[r][c] == 'X' || board[r][c] == '!') return;
        board[r][c] = '!';
        for (int i = 0; i < 4; ++i) {
            dfsTraversal(board, r + dirs[i], c + dirs[i+1]);
        }
        return;
    }
    int rLen, cLen;
    vector<int> dirs {1, 0, -1, 0, 1};
};
// TLE
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int rLen = board.size(), cLen = board[0].size();
        vector<vector<bool>> visited (rLen, vector<bool> (cLen, false));
        for (int r = 1; r < rLen; ++r) {
            for (int c = 1; c < cLen; ++c) {
                if (board[r][c] == 'O' && !visited[r][c]){
                    vector<pair<int, int>> flipIdx;
                    if (dfsFlip(board, visited, r, c, rLen, cLen, flipIdx)) {
                        for (const auto idx : flipIdx)
                            board[idx.first][idx.second] = 'X';
                    }
                }
            }
        }
        return;
    }
private:
    vector<int> dirs {1, 0, -1, 0, 1};
    bool dfsFlip(vector<vector<char>>& board, vector<vector<bool>> visited, 
                 int r, int c, int rLen, int cLen, vector<pair<int, int>>& flipIdx) {
        if (board[r][c] == 'X') return true;
        if (r == 0 || c == 0 || r == rLen - 1 || c == cLen -1) return false;
        visited[r][c] = true;
        flipIdx.push_back({r, c});
        bool flip = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i], nc = c + dirs[i+1];
            if (nr < 0 || nc < 0 || nr == rLen || nc == cLen || visited[nr][nc]) continue;
            flip = flip && dfsFlip(board, visited, nr, nc, rLen, cLen, flipIdx);
        }
        return flip;        
    }
};
// old answer

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        rLen = board.size();
        cLen = board[0].size();
        vector<vector<bool>> visited(rLen, vector<bool> (cLen, false));
        for(int i = 1; i < rLen-1; i++){
            for(int j = 1; j < cLen-1; j++){
                if(board[i][j] == 'O' && !visited[i][j])
                    solve(board, visited, i, j);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board, vector<vector<bool>>& visited, int rIdx, int cIdx){
        vector<pair<int,int>> path;
        if(check(board, visited, path, rIdx, cIdx)){
            for (const auto& p : path){
                board[p.first][p.second] = 'X';
            }
        }
        return;
    }
private:
    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<pair<int,int>>& path, int rIdx, int cIdx){
        if (visited[rIdx][cIdx] || board[rIdx][cIdx] == 'X') return true;
        if(rIdx == 0 || cIdx == 0 || rIdx == rLen-1 || cIdx == cLen-1) return false;
        else{
            visited[rIdx][cIdx] = true;
            path.push_back({rIdx, cIdx});
            bool res1 = check(board, visited, path, rIdx+1, cIdx);
            bool res2 = check(board, visited, path, rIdx-1, cIdx); 
            bool res3 = check(board, visited, path, rIdx, cIdx+1);
            bool res4 = check(board, visited, path, rIdx, cIdx-1);
            return res1 && res2 && res3 && res4;
        }
    }
    int rLen, cLen;
};
