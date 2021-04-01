// Revisit 20210212
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<int> curRes;
        vector<bool> visited(len, false);
        vector<vector<int>> res;
        dfsPermute(nums, curRes, res, visited);
        return res;
    }
private:
    void dfsPermute(vector<int>& nums, vector<int>& curRes, vector<vector<int>>& res, vector<bool>& visited) {
        if (curRes.size() == nums.size()) {
            res.push_back(curRes); return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (i != 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            curRes.push_back(nums[i]);
            visited[i] = true;
            dfsPermute(nums, curRes, res, visited);
            visited[i] = false;
            curRes.pop_back();
        }
        return;
    }
};

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
