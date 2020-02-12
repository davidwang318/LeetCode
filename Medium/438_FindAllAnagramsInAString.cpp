// Good way to use v1 == v2
// Time: 60.59%, Memory: 86.54%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty() || s.size() < p.size()) return{};
        vector<int> res, m1(26, 0), m2(26, 0);
        for (int i = 0; i < p.size(); i++){
            m1[s[i] - 'a']++;
            m2[p[i] - 'a']++;
        }
        if (m1 == m2) res.push_back(0);
        for(int i = p.size(); i < s.size(); i++){
            m1[s[i - p.size()] - 'a']--;
            m1[s[i] - 'a'] ++;
            if(m1 == m2) res.push_back(i-p.size()+1);
        }
        return res;
    }
};

// First Implementation, not a good way.
// Time: 48.92%, Memory: 63.46% 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> m;
        for (const auto letter : p) m[letter] ++;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            m[s[i]]--;
            if(++cnt == p.size()){
                bool success = true;
                for (const auto it : m){
                    success = success && (it.second == 0);
                }
                if (success) res.push_back(i-cnt+1);
                m[s[i-cnt+1]]++; cnt--;
            }
        }
        return res;
    }
};
