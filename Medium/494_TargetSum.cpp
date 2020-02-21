// First Attempt, using DFS and Memorization
// Time: 77.59%, Space: 30.77%

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (const auto num : nums) sum += num;
        vector<vector<int>> dp(nums.size(), vector<int> (2*sum+1, -1));
        int offset = sum - S;
        return dfs(nums, dp, 0, S, offset);

    }

    int dfs(vector<int>& nums, vector<vector<int>>& dp, int i, long int s, int o) {
        if(i == nums.size()) return (s == 0) ? 1 : 0;
        int col = s + o;
        if(dp[i][col] == -1) dp[i][col] = dfs(nums, dp, i+1, s-nums[i], o) + dfs(nums, dp, i+1, s+nums[i], o);
        return dp[i][col];
    }
};

// DP
// Time: 56.51%, Space 15.38
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        vector<unordered_map<int, int>> dp(len+1);
        dp[0][0] = 1;
        for(int i = 0; i < len; i++){
            for (const auto &m : dp[i]){
                dp[i+1][m.first+nums[i]] += m.second;
                dp[i+1][m.first-nums[i]] += m.second;
            }
        }
        return dp[len][S];
    }
};
