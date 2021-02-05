class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() <= 2) return s.size();
        int cnt = 0, l = 0, r = 0, res = 0;
        unordered_map<char, int> m;
        while (r != s.size()) {
            if (cnt > 2) {
                if (--m[s[l++]] == 0) --cnt;
            }
            else {
                if (m[s[r++]]++ == 0) ++cnt;
                if (cnt > 2) continue;
                else res = max(res, r - l);
            }
        }
        return res;
    }
};