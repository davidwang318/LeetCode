// Recursive version:
class Solution {
public:
    string decodeString(string s) {
        int i = 0, len = s.size();
        return healper(s, i, len);        
    }
    
    string healper(string s, int& i, int& len){
        string res = "";
        int cnt = 0;
        while(i < len && s[i] != ']'){
            if(s[i] < '0' || s[i] > '9') res += s[i++];
            else{
                while(s[i] != '[') cnt = cnt*10 + (s[i++] - '0');
                i ++;
                string tmp = healper(s, i, len);
                while(cnt > 0){
                    res += tmp; cnt--;
                }
                i ++;
            }
        }
        return res;
    }
    
};
