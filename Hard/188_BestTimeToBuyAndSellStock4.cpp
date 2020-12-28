// If you understand the general solution of buy&sell3, its easy
// But very hard to understand
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        vector<vector<int>> global(len, vector<int>(k+1, 0)), local(len, vector<int>(k+1, 0));
        for (int i = 1; i < len; i++) {
            int diff = prices[i] - prices[i-1];
            // i + 1 because i starts from 0, j should starts from 1
            for (int j = 1; j < k+1; j++) {
                local[i][j] = max(global[i-1][j-1], local[i-1][j]) + diff;
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }
        return global.back().back();

    }
};
