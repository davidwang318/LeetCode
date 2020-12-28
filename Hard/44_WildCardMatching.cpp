// My answer, pretty slow
class Solution {
public:
    bool isMatch(string s, string p) {
        sLen = s.size();
        pLen = p.size();
        dp.resize(sLen+1, vector<int>(pLen+1, -1));
        return dfs(s, p, 0, 0);
    }
private:
    bool dfs(string& s, string& p, int sStart, int pStart) {
        int dpRow = sStart, dpCol = pStart;
        if (dp[dpRow][dpCol] != -1) return dp[dpRow][dpCol];
        while(sStart < sLen && pStart < pLen && (s[sStart] == p[pStart] || p[pStart] == '?')) {
                sStart ++;
                pStart ++;
        }
        if (pStart != pLen && p[pStart] == '*') {
            bool res = false;
            for (int i = sStart; i <= sLen; i++) {
                    res |= dfs(s, p, i, pStart + 1);
            }
            dp[dpRow][dpCol] = res;
            return res;
        }
        dp[dpRow][dpCol] = (sStart == sLen && pStart == pLen)? true : false;
        return dp[dpRow][dpCol];
    }
    int sLen, pLen;
    vector<vector<int>> dp;
};
