class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n, vector<int> (n, 0));
        int rIdx = 0, cIdx = -1, num = 1;
        for (int i = n-1; i >= 0; i-=2){
            int times = (i)? i * 4 : 1;
            for (int j = 0; j < times; j++){
                int caseNum = (j == 0)? 0 : (j-1) / i;
                if (caseNum == 0) cIdx++;
                else if (caseNum == 1) rIdx++;
                else if (caseNum == 2) cIdx--;
                else rIdx--;
                res[rIdx][cIdx] = num++;
            }
        }
        return res;
    }
};
