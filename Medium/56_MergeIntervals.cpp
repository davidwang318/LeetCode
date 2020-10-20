class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto vec : intervals){
            if(res.empty() || res.back()[1] < vec[0]) res.push_back(vec);
            else res.back()[1] = max(res.back()[1], vec[1]);
        }
        return res;
    }
};
