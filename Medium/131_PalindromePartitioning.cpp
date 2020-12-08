// Remember to use dp (make use of the properties of palindrome)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        len = s.size();
        vector<string> cur;
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        for (int end = 0; end < len; end++){
            for (int start = 0; start <= end; start++){
                if (s[start] == s[end] && (end - start <= 2 || dp[start+1][end-1])){
                    dp[start][end] = true;
                }
            }
        }
        dfs(s, cur, 0, dp);
        return res;
    }
private:
    void dfs(string& s, vector<string>& cur, int start, vector<vector<bool>>& dp){
        if (start == len) {
            res.push_back(cur);
            return;
        }
        for (int i = 1; i < len - start + 1; i ++){
            if (dp[start][start+i-1]){
                string curString = s.substr(start, i);
                cur.push_back(curString);
                dfs(s, cur, start + i, dp);
                cur.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> res;
    int len;
};
