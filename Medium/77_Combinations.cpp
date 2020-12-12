// Not hard. Need to be careful
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        vector<int> cur;
        vector<vector<int>> res;
        dfs(res, cur, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int start) {
        int len = cur.size();
        if (len == k_) {
            res.push_back(cur);
            return;
        }
        for(int i = start+1; i <= n_ - k_ + 1 + len; i++) {
            cur.push_back(i);
            dfs(res, cur, i);
            cur.pop_back();
        }
        return;
    }
    int n_, k_;
};
