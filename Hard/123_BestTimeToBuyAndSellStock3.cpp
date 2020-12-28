// In my opinion, the correct approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        vector<int> minP (len, 0), maxP(len, 0), lProfit(len, 0), rProfit(len, 0);
        minP[0] = prices[0]; maxP.back() = prices.back();
        // Compute the min / max array
        for (int i = 1; i < len; i++) {
            int j = len - i - 1;
            minP[i] = min(minP[i-1], prices[i]);
            maxP[j] = max(maxP[j+1], prices[j]);
        }
        // Compute the maximum profit with 2 transaction
        int res = 0;
        for (int i = 1; i < len; i++) {
            int j = len - i - 1;
            lProfit[i] = max(lProfit[i-1], prices[i] - minP[i]);
            rProfit[j] = max(rProfit[j+1], maxP[j] - prices[j]);
        }
        for (int i = 0; i < len; i++)
            res = max(lProfit[i] + rProfit[i], res);
        return res;
    }
};

// General solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        vector<vector<int>> global(len, vector<int>(3, 0)), local(len, vector<int>(3, 0));
        for (int i = 1; i < len; i++) {
            int diff = prices[i] - prices[i-1];
            // i + 1 because i starts from 0, j should starts from 1
            for (int j = 1; j < min(3, i+1); j++) {
                local[i][j] = max(global[i-1][j-1], local[i-1][j]) + diff;
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }
        return max(global[len-1][1], global[len-1][2]);
    }
};
