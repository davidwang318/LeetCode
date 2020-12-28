// The key is how to define dp[i][j]
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        len = nums.size();
        vector<vector<int>> dp(len, vector<int> (len, 0));
        return burst(nums, dp, 0, len-1);
    }
private:
    int burst(vector<int>& nums, vector<vector<int>>& dp, int i, int j) {
        if (i < 0 || j < 0 || i == len || j == len || j < i) return 0;
        if (dp[i][j] != 0) return dp[i][j];
        int lNum = (i == 0) ? 1 : nums[i - 1];
        int rNum = (j == len - 1)? 1 : nums[j + 1];
        if (i == j) return dp[i][j] = nums[i] * lNum * rNum;
        for (int k = i; k <= j; k++) {
            dp[i][j] = max(dp[i][j], burst(nums, dp, i, k-1) + burst(nums, dp, k+1, j) + lNum * rNum * nums[k]);
        }
        return dp[i][j];
    }
    int len;
};

// Bottoms up
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int> (len, 0));
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                // update: dp[j-i][j]
                int lNum = j - i - 1 >= 0? nums[j-i-1] : 1;
                int rNum = j + 1 < len? nums[j+1] : 1;
                for (int k = j-i; k <= j; k++) {
                    int ldp = k-1 >= 0 ? dp[j-i][k-1] : 0;
                    int rdp = k+1 < len? dp[k+1][j] : 0;
                    dp[j-i][j] = max(dp[j-i][j], lNum*rNum*nums[k] + ldp + rdp);
                }
            }
        }
        return dp[0].back();
    }
};
