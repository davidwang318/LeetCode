class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.size() <= k) return s.size();
        int cnt = 0, l = 0, r = 0, res = 0;
        unordered_map<char, int> m;
        while (r != s.size()) {
            if (cnt > k) {
                if (--m[s[l++]] == 0) --cnt;
            }
            else {
                if (m[s[r++]]++ == 0) ++cnt;
                if (cnt > k) continue;
                else res = max(res, r - l);
            }
        }
        return res;
    }
};