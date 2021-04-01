// First visit, fail to complete.
// Levenshtein distance
// Time: 81.77%, Memory: 51.15%
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else {
                    dp[i][j] = min(dp[i-1][j-1] + (word1[i-1] == word2[j-1]? 0 : 1), min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                }
            }
        }
        return dp.back().back();
    }
};
// recursive solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        return recursive(word1, word2, word1.size(), word2.size());        
    }
private:
    int recursive(string& word1, string& word2, int end1, int end2) {
        auto it = m.find({end1, end2});
        if (it != m.end()) return it -> second;
        if (end1 == 0) return m[{end1, end2}] = end2;
        if (end2 == 0) return m[{end1, end2}] = end1;
        int cost = (word1[end1-1] == word2[end2-1])? 0 : 1;
        return m[{end1, end2}] = min(recursive(word1, word2, end1-1, end2-1) + cost, 
                   min(recursive(word1, word2, end1-1, end2) + 1, recursive(word1, word2, end1, end2-1) + 1));
    }
    map<pair<int, int>, int> m;
};