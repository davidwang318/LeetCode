// This is not a good approach, but it can still be done
// Time: 79.46%, Space: 76.58%
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return matrix;
        vector<int> dirs {-1, 0, -1};
        vector<vector<bool>> update (matrix.size(), vector<bool>(matrix[0].size(), false));
        // go + & +
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                if (matrix[r][c] == 0) {
                    update[r][c] = true; continue;
                }
                int mNum = INT_MAX;
                for (int i = 0; i < 2; ++i) {
                    int nr = r + dirs[i], nc = c + dirs[i+1];
                    if (nr < 0 || nc < 0 || nr == matrix.size() || nc == matrix[0].size() || !update[nr][nc]) continue;
                    mNum = min(mNum, matrix[nr][nc]);
                }
                if (mNum != INT_MAX) {
                    if (!update[r][c]) matrix[r][c] = 1 + mNum;
                    else matrix[r][c] = min(matrix[r][c], 1 + mNum);
                    update[r][c] = true;
                }
            }
        }
        for (int r = matrix.size()-1; r >= 0; --r) {
            for (int c = matrix[0].size()-1; c >= 0; --c) {
                if (matrix[r][c] == 0) continue;
                int mNum = INT_MAX;
                for (int i = 0; i < 2; ++i) {
                    int nr = r - dirs[i], nc = c - dirs[i+1];
                    if (nr < 0 || nc < 0 || nr == matrix.size() || nc == matrix[0].size()) continue;
                    mNum = min(mNum, matrix[nr][nc]);
                }
                if (mNum != INT_MAX) {
                    if (!update[r][c]) matrix[r][c] = 1 + mNum;
                    else matrix[r][c] = min(matrix[r][c], 1 + mNum);
                    update[r][c] = true;
                }
            }
        }

        return matrix;        
    }
};