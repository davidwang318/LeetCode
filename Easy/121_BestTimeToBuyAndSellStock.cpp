class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, res = INT_MIN;
        for (const auto& p : prices) {
            res = max(res, p - minPrice);
            minPrice = min(minPrice, p);
        }
        return res > 0 ? res : 0;
    }
};
