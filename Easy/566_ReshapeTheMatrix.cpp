// Very easy question.
// Time: 92.57%. Space: 68.00%
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty() || nums[0].empty()) return nums;
        const int row = nums.size(), col = nums[0].size();
        if (row*col != r*c) return nums;
        vector<vector<int>> res(r, vector<int> (c, 0));
        
        for(int i = 0; i < r*c; i++){
            int oldR = i / col, oldC = i % col;
            int newR = i / c, newC = i % c;
            res[newR][newC] = nums[oldR][oldC];
        }
        return res;
    }
};

