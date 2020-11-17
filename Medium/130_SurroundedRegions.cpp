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
