// Revisit, 20210216
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subRes;
        vector<bool> visited (candidates.size(), false);
        dfs(res, subRes, visited, candidates, target, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& subRes, vector<bool>& visited, 
             vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(subRes);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            if (i != start && candidates[i] == candidates[i-1] && !visited[i-1]) continue;
            subRes.push_back(candidates[i]);
            visited[i] = true;
            dfs(res, subRes, visited, candidates, target - candidates[i], i+1);
            visited[i] = false;
            subRes.pop_back();
        }
        return;
    }
};

// Time: 82.07%, Memory: 100.00%
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subres;
        sort(candidates.begin(), candidates.end());
        dfsSum2(res, subres, candidates, target, 0);
        return res;
    }
    void dfsSum2(vector<vector<int>>& res, vector<int>& subRes, vector<int>& candi, int target, int start){
        if(target == 0) {
            res.push_back(subRes);
            return;
        }
        for(int i = start; i < candi.size(); i++){
            if(candi[i] > target) break;
            if(i > start && candi[i-1] == candi[i]) continue;
            subRes.push_back(candi[i]);
            dfsSum2(res, subRes, candi, target - candi[i], i+1);
            subRes.pop_back();
        }
        return;
    }
};
