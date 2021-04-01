/*
revisit 20210309

i stands for the ending index of text1
j stands for the ending index of text2
dp represents the best result from 0 to i and 0 to j

Note that no need to consider the result from x to i or y to j.
Because dp doesn't represent the best result include x to i.
It represents the best result from 0 to i, which includes x to i.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp (len1 + 1, vector<int> (len2 + 1, 0));
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (text1[i] == text2[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }        
        return dp.back().back();        
    }
};