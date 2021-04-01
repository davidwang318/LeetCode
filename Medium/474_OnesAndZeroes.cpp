// Revisit. Become easier but still need to be aware of the j & k index (0)
// Space optimization
// Time: 75.93%, Memory: 72.90%
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Construct a hash table
        vector<pair<int, int>> strsToCount;
        for (const auto& str : strs) {
            int count0 = 0, count1 = 0;
            for (const auto c : str) {
                if (c == '0') ++count0;
                else ++count1;
            }
            strsToCount.push_back({count0, count1});
        }
        
        // Construct a 2d backpack (space optimization)
        int len = strs.size();
        vector<vector<int>> backpack(m+1, vector<int> (n+1, 0));
        
        // Can select 1 ~ i th element
        for (int i = 1; i <= len; ++i) {
            auto [cur0, cur1] = strsToCount[i-1];
            // Have j size of the 0 backpack
            for (int j = m; j >= 0; --j) {
                // Have k size of the 1 backpack
                for (int k = n; k >= 0; --k) {
                    if (cur0 <= j && cur1 <= k)
                        backpack[j][k] = max(backpack[j][k], backpack[j-cur0][k-cur1] + 1);
                }
            }
        }
        return backpack.back().back();
    }
};

// So hard to determine the start of j & k index
// Barely make through
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> strsToMn;
        for (const auto& str : strs) {
            int m_ = 0, n_ = 0;
            for (const auto c : str) {
                if (c == '0') ++m_;
                else ++n_;
            }
            strsToMn.push_back({m_, n_});
        }
        int len = strs.size();
        vector<vector<vector<int>>> dp (len + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, 0)));
        for (int i = 0; i < len; ++i) {
            auto [count0, count1] = strsToMn[i];
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                        if (count0 <= j && count1 <= k)
                            dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-count0][k-count1] + 1);
                        else
                            dp[i+1][j][k] = dp[i][j][k];  
                    
                }
            }
        }
        return dp.back().back().back();
    }
};