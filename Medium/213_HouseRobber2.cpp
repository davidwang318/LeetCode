class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size() + 1, 0), dp2(nums.size() + 1, 0);
        for(int i = 0; i < nums.size()-1; i++){
            dp1[i+2] = max(nums[i] + dp1[i], dp1[i+1]);
            dp2[i+2] = max(nums[i+1] + dp2[i], dp2[i+1]);
        }
        return max(dp1.back(), dp2.back());        
    }
};
