// First attempt. Need to review DFS.
// Time: 97.25%, Memory: 100.00%
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subRes;
        sort(candidates.begin(), candidates.end());
        dfsSum(candidates, subRes, res, target, 0);
        return res;
        
    }
private:
    void dfsSum(vector<int>& candidates, vector<int>& subRes, vector<vector<int>>& res, int target, int start){
        int len = candidates.size();
        if(target == 0){
            res.push_back(subRes);
            return;
        }
        for(int i = start; i < len; i++){
            if(candidates[i] > target) break;
            subRes.push_back(candidates[i]);
            dfsSum(candidates, subRes, res, target - candidates[i], i);
            subRes.pop_back();
        }
        return;
    }
};
