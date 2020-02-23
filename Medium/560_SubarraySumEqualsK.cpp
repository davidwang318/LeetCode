// First Attemp. Use dp and hash table.
// Time: 39.98%, Space: 5.34%
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size(), res = 0;
        unordered_map<int, vector<int>> m;
        vector<int> dp(len+1, 0);
        for (int i = 0; i < len; i++) {
            dp[i+1] = dp[i] + nums[i];
            m[dp[i+1]].push_back(i+1);
        }
        for (int i = 0; i < len+1; i++){
            int target = k + dp[i];
            if(m[target].size() > 0){
                for(const auto idx : m[target]) if(idx > i) res++;
            }
        }
        return res;
    }
};

// Amazing!
// Time: 64.45%, Space: 30.67%
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size(), sum = 0, res = 0;
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < len; i++){
            sum += nums[i];
            res += m[sum-k];
            m[sum] ++;
        }
        return res;
    }
};
