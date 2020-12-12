class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        int aLen = a.size(), bLen = b.size(), lenDiff = aLen - bLen;
        string sum;
        for (int i = 0; i < aLen; i++){
            if (i < lenDiff) sum += a[i];
            else {
                int j = i - lenDiff;
                if (a[i] == '1' && b[j] == '1') sum += '2';
                else if (a[i] == '0' && b[j] == '0') sum += '0';
                else sum += '1';
            }
        }
        string dummy = "1";
        bool carry = false;
        for (int i = sum.size() - 1; i >= 0; i --) {
            if (carry) {
                if (sum[i] == '0') {
                    sum[i] = '1';
                    carry = false;
                }
                else if (sum[i] == '1') {
                    sum[i] = '0'; 
                    carry = true;
                }
                else {
                    sum[i] = '1';
                    carry = true;
                }
            }
            else {
                if (sum[i] == '2') {
                    sum[i] = '0';
                    carry = true;
                }
            }
        }
        return carry? dummy+sum : sum;
    }
};
