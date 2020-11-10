class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rLen = A.size(), cLen = A[0].size();
        for(int i = 0; i < rLen; i ++){
            for(int j = 0; j < (cLen+1) / 2; j++){
                int k = cLen - j - 1;
                if(A[i][j] == A[i][k]){
                    A[i][j] = A[i][k] = (A[i][j] == 0)? 1 : 0;
                }
            }
        }
        return A;
    }
};
