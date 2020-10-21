class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i-1]) - 1;
            if(dp[i] < 0) return false;
        }
        return true;
    }
};
