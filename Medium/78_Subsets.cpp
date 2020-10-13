// Easy
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subRes;
        subsets(res, subRes, nums, 0);
        return res;
    }
    void subsets(vector<vector<int>>& res, vector<int>& vec, vector<int>& nums, int idx){
        if(idx == nums.size()){
            res.push_back(vec);
            return;
        }
        subsets(res, vec, nums, idx+1);
        vec.push_back(nums[idx]);
        subsets(res, vec, nums, idx+1);
        vec.pop_back();
        return;
    }
};
