// My answer
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        rLen = matrix.size(); cLen = matrix[0].size();
        vector<vector<bool>> visited(rLen, vector<bool> (cLen, false));
        vector<int> res;
        int moveCase = 0;
        spiralTravel(matrix, visited, res, 0, 0, moveCase);
        return res;
    }
private:
    void spiralTravel(vector<vector<int>>& matrix, vector<vector<bool>>& visited, 
                      vector<int>& res, int rIdx, int cIdx, int moveCase){
        cout << matrix[rIdx][cIdx] << endl;
        res.push_back(matrix[rIdx][cIdx]);
        visited[rIdx][cIdx] = true;
        if(checkEnd(visited, rIdx, cIdx)) return;
        checkCase(visited, rIdx, cIdx, moveCase);
        switch(moveCase){
            case 0:
                cIdx = cIdx+1;
                break;
            case 1:
                rIdx = rIdx+1;
                break;
            case 2:
                cIdx = cIdx-1;
                break;
            case 3:
                rIdx = rIdx-1;
                break;
        }
        spiralTravel(matrix, visited, res, rIdx, cIdx, moveCase);
        return;
    }
    
    void checkCase(vector<vector<bool>>& visited, int rIdx, int cIdx, int& moveCase){
        int new_rIdx, new_cIdx;
        switch(moveCase){
            case 0:
                new_rIdx = rIdx; new_cIdx = cIdx+1;
                break;
            case 1:
                new_rIdx = rIdx+1; new_cIdx = cIdx;
                break;
            case 2:
                new_rIdx = rIdx; new_cIdx = cIdx-1;
                break;
            case 3:
                new_rIdx = rIdx-1; new_cIdx = cIdx;
                break;
        }
        if(new_rIdx < 0 || new_cIdx < 0 || new_rIdx >= rLen || new_cIdx >= cLen 
                    || visited[new_rIdx][new_cIdx]) moveCase++;
        moveCase %= 4;
        return;
    }
    
    bool checkEnd(vector<vector<bool>>& visited, int rIdx, int cIdx){
        bool check = true;
        if (rIdx-1 >= 0) check = check && visited[rIdx-1][cIdx];
        if (rIdx+1 < rLen) check = check && visited[rIdx+1][cIdx];
        if (cIdx-1 >= 0) check = check && visited[rIdx][cIdx-1];
        if (cIdx+1 < cLen) check = check && visited[rIdx][cIdx+1];
        return check;
    }
    
    int rLen = 0, cLen = 0;
};
