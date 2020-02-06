class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for(int i = 0; i < nums.size(); i++){
            if(indices.count(target - nums[i])) return {i, indices[target - nums[i]]};
            indices[nums[i]] = i;
        }
        return {};
    }
};
