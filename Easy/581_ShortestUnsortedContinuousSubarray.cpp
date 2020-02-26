// Suprisingly hard...
// Time: 77.12%, Memory: 71.43%
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size(), maxl = nums[0], minr = nums[len-1] ;
        int idxl = 0, idxr = -1;
        for(int i = 1; i < len; i++){
            maxl = max(maxl, nums[i]);
            minr = min(minr, nums[len-1-i]);
            if(maxl > nums[i]) idxr = i;
            if(minr < nums[len-1-i]) idxl = len-1-i;
        }
        return idxr-idxl+1;        
    }
};
