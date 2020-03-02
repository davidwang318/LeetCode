// First Attempt. Inspired by Grandyand.
// Time: 52.90%, Memory: 100.00%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        int len = nums.size();
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        // Edge case check
        if(nums.empty() || nums[0] > 0 || nums.back() < 0) return {};

        for(int i = 0; i < len-2; i++){
            if(nums[i] > 0) break;
            // Duplicate target check
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i], idx1 = i+1, idx2 = len-1;
            while(idx1 < idx2){
                // Duplicate check
                if(idx1 != i+1 && idx1 < idx2 && nums[idx1] == nums[idx1-1]){
                    idx1++; continue;
                }
                if(idx2 != len-1 && idx1 < idx2 && nums[idx2] == nums[idx2+1]){
                    idx2--; continue;
                }
                // Target check
                int cur = nums[idx1] + nums[idx2];
                if(cur == target){
                    res.push_back({nums[i], nums[idx1], nums[idx2]});
                    idx1++; idx2--;
                }
                else{
                    if(cur < target) idx1++;
                    else idx2--;
                }
            }
        }      
        return res;        
    }
};

