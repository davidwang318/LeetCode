// Time: 56.51%, Space: 50.00%
class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        string res, sign;
        if(num < 0) {
            sign = "-"; 
            num = abs(num);
        }
        while(num > 0){
            res = std::to_string(num%7) + res;
            num /= 7;
        }
        return sign + res;        
    }
};
