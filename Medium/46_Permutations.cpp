// Pretty easy
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> out;
        vector<bool> visited (nums.size(), false);
        permute(res, nums, out, visited);
        return res;        
    }
    void permute(vector<vector<int>>& res, vector<int>& nums, vector<int>& out, vector<bool>& visited){
        if(out.size() == nums.size()){
            res.push_back(out);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            out.push_back(nums[i]);
            visited[i] = true;
            permute(res, nums, out, visited);
            out.pop_back();
            visited[i] = false;
        }
        return;
    }
};
