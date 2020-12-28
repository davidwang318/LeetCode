class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i < rowIndex + 1; i++) {
            vector<int> cur(i+1);
            for (int j = 0; j < i+1; j++) {
                if (j == 0 || j == i) cur[j] = 1;
                else cur[j] = res[j-1] + res[j];
            }
            res = cur;
        }
        return res;        
    }
};
