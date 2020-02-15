// Time: 100.00% Space: 100.00%
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res; 
        std::map<int, int> m;
        for(const auto num1 : arr1) m[num1]++;
        for(const auto num2 : arr2){
            while(m[num2]-- > 0) res.push_back(num2);
        }
        for(auto i : m){
            while(i.second-- > 0) res.push_back(i.first);
        }
        return res;        
    }
};
