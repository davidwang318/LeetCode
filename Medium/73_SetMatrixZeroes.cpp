// First Attemp. Saw this one in the "Cracking The Coding Interview".
// Time: 92.50%, Memory: 100.00%
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroRow = false, zeroCol = false;
        int rlen = matrix.size(), clen = matrix[0].size();
        for(int j = 0; j < clen; j++) if(matrix[0][j] == 0) zeroRow = true;
        for(int i = 0; i < rlen; i++) if(matrix[i][0] == 0) zeroCol = true;
        for(int i = 1; i < rlen; i++){
            for(int j = 1; j < clen; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int j = 1; j < clen; j++) if(matrix[0][j] == 0) setColZeros(matrix, j);
        for(int i = 1; i < rlen; i++) if(matrix[i][0] == 0) setRowZeros(matrix, i);
        if(zeroRow) setRowZeros(matrix, 0);
        if(zeroCol) setColZeros(matrix, 0);
        
    }
private:
    void setRowZeros(vector<vector<int>>& matrix, int ridx){
        for(int j = 0; j < matrix[0].size(); j++) matrix[ridx][j] = 0;
        return;
    }
    void setColZeros(vector<vector<int>>& matrix, int cidx){
        for(int i = 0; i < matrix.size(); i++) matrix[i][cidx] = 0;
        return;
    }
};
