// Time: 19.04%, Memory: 100.00%
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowTable(9, vector<bool>(9, false)), 
                             colTable(9, vector<bool>(9, false)),
                             cellTable(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'1', cell = (i/3)*3 + j/3;
                if(rowTable[i][num] || colTable[j][num] || cellTable[cell][num]) return false;
                rowTable[i][num] = true;
                colTable[j][num] = true;
                cellTable[cell][num] = true;
            }
        }
        return true;
    }
};
