class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size();
        // Find cnt distinct char
        for (int cnt = 1; cnt <= 26; ++cnt) {
            // Starts from start, ends at i
            int start = 0, i = 0, uniqueCnt = 0, kCnt = 0;
            vector<int> charCnt(26);
            // Scan the whole string
            while (i < n) {
                bool valid = true;
                // Accumulate unique char
                if (charCnt[s[i++] - 'a']++ == 0) ++uniqueCnt;
                // decrease left bound when necessary
                while (uniqueCnt > cnt) {
                    if (--charCnt[s[start++] - 'a'] == 0) --uniqueCnt;
                }
                // Check is it valid
                for (int j = 0; j < 26; ++j) {
                    if (charCnt[j] > 0 && charCnt[j] < k) valid = false;
                }
                if (valid) res = max(res, i - start);
            }
        }    
        return res;
    }
};