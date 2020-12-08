// Hard...
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(len < 2) return 0;
        // Valid palindrome graph
        vector<vector<bool>> valid(len, vector<bool> (len, false));
        for (int end = 0; end < len; end ++){
            for (int start = 0; start <= end; start++){
                if (s[start] == s[end] && (end - start <= 2 || valid[start+1][end-1]))
                    valid[start][end] = true;
            }
        }
        // Dynamic programming
        vector<int> dp(len, len-1);
        for (int i = 0; i < len; i++){
            if (valid[0][i]){
                dp[i] = 0; continue;
            }
            for (int j = 0; j < i; j++){
                if (valid[j+1][i])
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
        return dp.back();
    }
};
// Better solution

