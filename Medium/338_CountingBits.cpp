// My answer:

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        int cnt = 0;
        for(int i = 1; i <= num; i++){
            if(i == (1 << cnt)){
                res[i] = 1;
                cnt++;
            }
            else res[i] = res[i - (1 << (cnt - 1))] + 1;
        }
        return res;
    }
};

// Answer in discussion:

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for(int i = 1; i <= num; i++) res[i] = res[i & (i-1)] + 1;
        return res;
    }
};
