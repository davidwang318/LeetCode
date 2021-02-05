/* Using Bucket Sort */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int maxCnt = 0;
        for(const auto& num : nums)
            maxCnt = max(maxCnt, ++m[num]);
        vector<vector<int>> buckets (maxCnt);
        for(const auto& i : m) 
            buckets[i.second-1].push_back(i.first);
        vector<int> res;
        while(res.size() < k) {
            for (const auto& i : buckets.back())
                res.push_back(i);
            buckets.pop_back();
        }
        return res;
    }
};

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
