class Solution {
public:
    bool validPalindrome(string s) {
        int lPtr = 0, rPtr = s.size()-1;
        while(lPtr <= rPtr) {
            if (s[lPtr] == s[rPtr]) {
                ++lPtr; --rPtr;
            }
            else {
                return helper(s, lPtr+1, rPtr) || helper(s, lPtr, rPtr-1);
            }
        }
        return true;
    }
private:
    bool helper(string& s, int lPtr, int rPtr) {
        while(lPtr <= rPtr) {
            if (s[lPtr] == s[rPtr]) {
                ++lPtr; --rPtr;
            }
            else return false;
        }
        return true;
    }
};