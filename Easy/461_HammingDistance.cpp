// 0ms
class Solution {
public:
    int hammingDistance(int x, int y) {
        int hDist = 0;
        for (int i = 0; i < 32; i++){
            // hDist += (x % 2 != y % 2);
            hDist += ((x&1) != (y&1));
            // x /= 2; y /= 2;
            x >>= 1;
            y >>= 1;
            if(!(x || y)) break;
        }
        return hDist;
    }
};

// Good use of XOR
class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorbit = x^y, hDist = 0;
        while(xorbit > 0){
            hDist += xorbit & 1;
            xorbit >>= 1;
        }
        return hDist;
    }
};

