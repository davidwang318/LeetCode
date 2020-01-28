/* Using set version */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        set<pair<int, int>> s;
        vector<int> res;
        for(auto num : nums) hash[num]++;
        for(auto it : hash) s.insert({it.second, it.first});
        auto rit = s.rbegin();
        while(k > 0){
            res.push_back(rit -> second);
            rit++;
            k--;
        }
        return res;
    }
};
