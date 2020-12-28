// My solution
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> m;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (const auto& word : wordDict) m[word] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    string tmp = s.substr(j, i-j);
                    dp[i] = dp[i] || m[tmp];
                }
            }
        }
        return dp.back();        
    }
};
// Recursive Method
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet {wordDict.begin(), wordDict.end()};
        return wordBreak(s, wordSet);
    }
    bool wordBreak(string& s, unordered_set<string>& wordSet) {
        if (m_.count(s)) return m_[s];
        if (wordSet.count(s)) return m_[s] = true;
        for (int i = 1; i < s.size(); i++) {
            string sLeft = s.substr(0, i);
            if (wordSet.count(sLeft)) {
                string sRight = s.substr(i);
                if (wordBreak(sRight, wordSet))
                    return m_[s] = true;
            }
        }
        return m_[s] = false;
    }
private:
    unordered_map<string, bool> m_;
};
