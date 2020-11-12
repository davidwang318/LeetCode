class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(auto c : t) m[c]++;
        int cnt = 0, left = 0, minLeft = 0, minLen = INT_MAX;
        for(int i = 0; i < s.size(); i ++){
            if (m[s[i]]-- > 0) cnt++;
            while(cnt == t.size()){
                if(i - left < minLen){
                    minLen = i - left + 1;
                    minLeft = left;
                }
                if(m[s[left++]]++ >= 0)  cnt--;
            }
        }
        return minLen == INT_MAX? "" : s.substr(minLeft, minLen);
        
    }
};
