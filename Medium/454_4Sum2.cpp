class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size(), res = 0;
        unordered_map<int, int> m1, m2;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                m1[A[i] + B[j]]++;
                m2[C[i] + D[j]]++;
            }
        }
        for (const auto a : m1){
            res += a.second * m2[-a.first];
        }
        return res;
    }
};
