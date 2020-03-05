// First Attempt. Not a difficult problem.
// Time: 99.29%, Memory: 100.00%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int cnt = 1, len = nums.size();
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[i-1]){
                nums[cnt++] = nums[i];
            } 
        }
        return cnt;
    }
};
