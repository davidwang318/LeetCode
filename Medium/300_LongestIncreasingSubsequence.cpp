class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int maxL = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            maxL = max(maxL, dp[i]);
        }
        return maxL;
    }
};

// Hard to follow the concept.
// Binary search is so important!
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp;
        for(const auto num : nums){
            if (dp.empty()) dp.push_back(num);
            else if (num <= dp[0]) dp[0] = num;
            else if (num > dp.back()) dp.push_back(num);
            else{
                int left = 0, right = dp.size();
                while(left < right){
                    int mid = (right - left) / 2 + left;
                    if(dp[mid] >= num) right = mid;
                    else left = mid + 1;
                }
                dp[left] = num;
            }
        }
        return dp.size();
    }
};
