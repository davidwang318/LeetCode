// Easy solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int cnt = 0, res = 0;
        for(int i = 0; i < len; i++){
            if (s[i] != ' ') cnt++;
            else{
                if (cnt != 0) res = cnt;
                cnt = 0;
            }
        }
        // Check the last time
        return cnt > 0? cnt : res;
    }
};
