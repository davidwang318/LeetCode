class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /**
        hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
        sold[i] = hold[i-1] + prices[i];
        rest[i] = max(rest[i-1], sold[i-1]);
        **/
        if (prices.empty()) return 0;
        int len = prices.size();
        vector<int> hold(len, 0), rest(len, 0), sold(len, 0);
        hold[0] = -prices[0]; rest[0] = sold[0] = 0;
        for (int i = 1; i < len; i++) {
            hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
            sold[i] = hold[i-1] + prices[i];
            rest[i] = max(rest[i-1], sold[i-1]);
        }
        return max(rest.back(), sold.back());
        
    }
};
