// Time: 85.78%, Memory: 100.00%

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int len1 = haystack.size(), len2 = needle.size(), i = 0;
        if(len2 > len1) return -1;
        while( i <= len1-len2){
            string haystack2 = haystack.substr(i,len2);
            if(haystack2 == needle) return i;
            i++;
        }
        return -1;
    }
};
