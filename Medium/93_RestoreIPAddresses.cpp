// Simple DFS solution
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        if (len < 4 || len > 12) return {};
        for (int i = 0; i <= 2; i++) {
            dfs(s, 0, i, 1);
        }
        return res;
    }
private:
    void dfs(string& s, int start, int end, int level) {
        if (end >= s.size() || !valid(s, start, end) ) return;
        if (level == 4 && end == s.size() - 1) {
            res.push_back(s);
            return;
        }
        s.insert(end+1, ".");
        for (int i = 0; i <= 2; i++) {
            dfs(s, end+2, end+2+i, level+1);
        }
        s.erase(s.begin()+end+1);
        return;            
    }
    bool valid(string& s, int start, int end) {
        if (start != end && s[start] == '0') return false;
        int val = 0;
        for (int i = start; i <= end; i++) {
            val *= 10;
            val += (s[i] - '0');
        }
        return val <= 255;
    }
    vector<string> res;
};
