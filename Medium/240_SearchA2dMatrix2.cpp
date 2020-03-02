// Can't find a good way. Should start from the down left corner.
// Time: 40.33%, Memory: 100.00%
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back()) return false;
        int row = matrix.size()-1, col = 0;
        while(row >= 0 && col < matrix[0].size()){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) col++;
            else row--;
        }
        return false;
        
    }
};
