// First Attemp. Using HashTable
// Time: 93.34%, Memory: 56.68%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(m[target-nums[i]] > 0) return{i, m[target-nums[i]]-1};
            m[nums[i]] = i+1;
        }
        return {};
    }
};

// Better version: Use map.count()
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
