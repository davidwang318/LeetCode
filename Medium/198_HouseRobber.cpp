/*
days happend after won't affect the result happened before
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0, pre2 = 0;
        for (const auto num : nums) {
            int cur = max(num + pre2, pre);
            pre2 = pre;
            pre = cur;
        }
        return max(pre, pre2);
    }
};