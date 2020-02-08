class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int ans = 0, ind = 0;
        for(const auto& greed : g){
            while(ind < s.size() && s[ind] < greed) ind++;
            if(ind < s.size()){
                ans++;
                ind++;
            }
            else break;
        }
        return ans;
    }
};
