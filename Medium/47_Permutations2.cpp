// My solution:
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> resSet;
        vector<int> resHolder;
        permuteDfs(nums, resHolder, resSet, 0);
        for(const auto& s : resSet) res.push_back(s);
        return res;        
    }
private:
    void permuteDfs(vector<int>& nums, vector<int>& resHolder, set<vector<int>>& resSet, int idx){
        if (idx == nums.size()){
            resSet.insert(resHolder);
            return;
        }
        for(int i = 0; i <= resHolder.size(); i++){
            if(i == resHolder.size()) resHolder.push_back(nums[idx]);
            else{
                resHolder.insert(resHolder.begin()+i, nums[idx]);
            }
            permuteDfs(nums, resHolder, resSet, idx+1);
            resHolder.erase(resHolder.begin()+i);
        }
        return;
    }
};

// My solution is very slow.
