class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, amount + 1);
        int len = coins.size();
        dp[0] = 0;
        for (int i = 1; i < (amount+1); i++){
            for (int j = 0; j < len; j++){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return (dp.back() < amount + 1)? dp.back() : -1;  
    }
};
// revisit 2d method
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coinLen = coins.size();
        vector<vector<int>> dp (coinLen+1, vector<int> (amount+1, amount+2));
        dp[0][0] = 0;
        for (int i = 1; i <= coinLen; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j == 0) dp[i][j] = 0;
                else {
                    if (j >= coins[i-1])
                        dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp.back().back() == amount+2? -1 : dp.back().back();
    }
};
// revisit 2d intuitive method
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coinLen = coins.size();
        vector<vector<int>> dp (coinLen+1, vector<int> (amount+1, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= coinLen; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (j < coins[i-1])
                    dp[i][j] = dp[i-1][j];
                else {
                    if (dp[i-1][j] == -1 && dp[i][j-coins[i-1]] == -1)
                        dp[i][j] = -1;
                    else if (dp[i-1][j] == -1)
                        dp[i][j] = 1 + dp[i][j-coins[i-1]];
                    else if (dp[i][j-coins[i-1]] == -1)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
                
            }
        }
        return dp.back().back();
    }
};