// First trial, glad to finish, 20210216
// 8ms(89.53%)
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowSet(9, vector<bool>(9, false)), colSet(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> cellSet(3, vector<vector<bool>> (3, vector<bool>(9, false)));
        vector<pair<int, int>> dotSet;
        bool find = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    int chVal = ch - '1';
                    rowSet[i][chVal] = true;
                    colSet[j][chVal] = true;
                    cellSet[i/3][j/3][chVal] = true;
                }
                else dotSet.push_back({i, j});
            }
        }
        solve(board, dotSet, rowSet, colSet, cellSet, find);
        return;
    }
private:
    void solve(vector<vector<char>>& board, vector<pair<int,int>>& dotSet,  
               vector<vector<bool>>& rowSet, vector<vector<bool>>& colSet,
               vector<vector<vector<bool>>>& cellSet, bool& find) {
        if (dotSet.size() == 0) {
            find = true;
            return;
        }
        auto [r, c] = dotSet.back(); dotSet.pop_back();
        for (int i = 0; i < 9; ++i) {
            if (!rowSet[r][i] && !colSet[c][i] && !cellSet[r/3][c/3][i]) {
                rowSet[r][i] = colSet[c][i] = cellSet[r/3][c/3][i] = true;
                board[r][c] = i + '1';
                solve(board, dotSet, rowSet, colSet, cellSet, find);
                if (find) return;
                rowSet[r][i] = colSet[c][i] = cellSet[r/3][c/3][i] = false;               
            }
        }
        dotSet.push_back({r, c});
        return;
    }
};