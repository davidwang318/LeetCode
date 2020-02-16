class Solution {
public:
    bool checkRecord(string s) {
        int acnt = 0, lcnt = 0;
        for(const auto record : s){
            if(record == 'L') lcnt++;
            else{
                lcnt = 0;
                if(record == 'A') acnt++;
            }
            if(acnt > 1 || lcnt > 2) return false;
        }
        return true;
    }
};
