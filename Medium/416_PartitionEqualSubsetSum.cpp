// Revisit, so hard...
// Related to the 01 backpack problem
// This solution is using the same method as the next one, but without space optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numSum = 0;
        for (const auto num : nums) numSum += num;
        if (numSum % 2) return false;
        else numSum /= 2;
        int len = nums.size();
        vector<vector<bool>> dp (len + 1, vector<bool>(numSum + 1, 0));
        for (int i = 0; i < len; ++i) {
            dp[i][0] = true;
            for (int j = 1; j <= numSum; ++j) {
                if (j >= nums[i])
                    dp[i+1][j] = dp[i][j-nums[i]] || dp[i][j];
            }
        }
        return dp.back().back();
    }
};

// Great using of Dynamic Programming
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0), target = total >> 1;
        if(total&1) return false;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(const auto num : nums){
            for(int i = target; i >= num; i--){
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp.back();        
    }
};



// Can't pass OJ
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Brute force:
        if(nums.empty()) return false;
        return healper(nums, nums[0], 0, 1);
        
    }
    bool healper(vector<int>& nums, int sub1, int sub2, int i){
        if(i == nums.size()) return sub1 == sub2;
        return healper(nums, sub1+nums[i], sub2, i+1) || healper(nums, sub1, sub2+nums[i], i+1);
    } 
};
