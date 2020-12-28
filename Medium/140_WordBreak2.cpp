// Very hard to me
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet({wordDict.begin(), wordDict.end()});
        return wordBreak(s, wordSet);
    }
private:
    void append(vector<string>& lhs, string& rhs) {
        for (auto & s : lhs)
            s = rhs + " " + s;
        return;
    }
    vector<string> wordBreak(string& s, unordered_set<string>& wordSet) {
        // stop condition
        if (m_.count(s)) return m_[s];
        // current solution
        vector<string> res;
        if (wordSet.count(s))
            res.push_back(s);
        // other possible solutions
        for (int j = 1; j < s.size(); j++) {
            string left = s.substr(0, j);
            if (!wordSet.count(left)) continue;
            string right = s.substr(j);
            vector<string> subRes = wordBreak(right, wordSet);
            append(subRes, left);
            for (const auto& r : subRes)
                res.push_back(r);
        }
        m_[s] = res;
        return m_[s];
    }
    
    unordered_map<string, vector<string>> m_;
};
