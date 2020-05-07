// Hard for me. Need to practice more.
// Time: 100.00%, Space: 100.00%

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int len = s.size();
        vector<int> dp(len+1, 1);
        for(int i = 1; i < len+1; i++){
            dp[i] = s[i-1] == '0'? 0 : dp[i-1];
            if(i == 1) continue;
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1]-'0' <= 6)) 
                dp[i] += dp[i-2];
        }
        return dp.back();
    }
};
