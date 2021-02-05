/*
1, 2, 3, 4, 5, 6, 7, 8, 9
8, 9, 1, 2, 3, 4, 5, 6, 7 // nums[m] = 3, nums[r] = 7 -> nums[m] < nums[r] -> minimum at left -> r = m - 1
5, 6, 7, 8, 9, 1, 2, 3, 4 // m > r -> minimum at right -> l = m + 1
1, 2 -> m = 0 -> r = -1 -> return l 
2, 1 -> m = 0 -> l = 1 -> return l
3, 1, 2 -> special case
1, 2, 3 -> good
3, 2, 1 -> good
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if (r - l > 1 && nums[m] < nums[m+1] && nums[m] < nums[m-1]) return nums[m];
            if (nums[m] < nums[r]) r = m - 1;
            else l = m + 1;
        }
        return nums[l];
    }
};