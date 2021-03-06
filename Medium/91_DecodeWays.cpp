// Revisit 20210307
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp (s.size() + 1, 0);
        dp[0] = dp[1] = 1;
        int pre = s[0] - '0';
        for (int i = 1; i < s.size(); ++i) {
            int cur = s[i] - '0';
            if (cur == 0) {
                if (pre > 2 || pre == 0) return 0;
                dp[i+1] = dp[i-1];
            }
            else if (cur <= 6) {
                if (pre == 0 || pre > 2) dp[i+1] = dp[i];
                else dp[i+1] = dp[i] + dp[i-1];
            }
            else {
                if (pre == 1) dp[i+1] = dp[i] + dp[i-1];
                else dp[i+1] = dp[i];
            }
            pre = cur;
        }
        return dp.back();
    }
};
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

// Different approach
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int len = s.size();
        vector<int> dp(len + 1, 1);
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '0') dp[i] = 0;
            else{
                dp[i] = dp[i+1];
                if (i != len - 1 && (s[i] == '1' || s[i] == '2')) {
                    if (s[i] == '1' || (s[i] == '2' && s[i+1] - '0' <= 6)) dp[i] += dp[i+2];
                }
            }            
        }
        return dp[0];
    }
};
