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
