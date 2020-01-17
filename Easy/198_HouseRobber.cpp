class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size(), maxMoney{0};
        vector<int> dp(len+2, 0);
        for (int i = 2; i < len+2; i++){
            dp[i] = maxMoney + nums[i-2];
            maxMoney = max(maxMoney, dp[i-1]);            
        }
        return max(maxMoney, dp.back());
    }
};
