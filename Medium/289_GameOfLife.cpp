class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        rLen = board.size(), cLen = board[0].size();
        for(int i = 0; i < rLen; i++){
            for(int j = 0; j < cLen; j++){
                checkLife(board, i, j);
            }
        }
        for(auto & r : board){
            for(auto & c: r){
                c /= 2;
            }
        }
        return;
    }
private:
    void checkLife(vector<vector<int>>& board, int rIdx, int cIdx){
        int lifeNum = 0;
        if(rIdx > 0) lifeNum += board[rIdx-1][cIdx] % 2;
        if(cIdx > 0) lifeNum += board[rIdx][cIdx-1] % 2;
        if(rIdx < rLen-1) lifeNum += board[rIdx+1][cIdx] % 2;
        if(cIdx < cLen-1) lifeNum += board[rIdx][cIdx+1] % 2;
        if(rIdx > 0 && cIdx > 0) lifeNum += board[rIdx-1][cIdx-1] % 2;
        if(rIdx > 0 && cIdx < cLen-1) lifeNum += board[rIdx-1][cIdx+1] % 2;
        if(rIdx < rLen-1 && cIdx > 0) lifeNum += board[rIdx+1][cIdx-1] % 2;
        if(rIdx < rLen-1 && cIdx < cLen-1) lifeNum += board[rIdx+1][cIdx+1] % 2;         
        if(lifeNum == 3) board[rIdx][cIdx] += 2;
        else if(lifeNum == 2) {
            if(board[rIdx][cIdx]) board[rIdx][cIdx] = 3;
        }
        return;
    }
    int rLen = 0, cLen = 0;
};
