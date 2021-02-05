/*
1, 1, 2, 2, 3, 3, 4, 4, 5, 5 (m = 3, m+1 = 3)
1, 1, 2, 3, 3, 4, 4, 5, 5 (m = 3, m == m - 1) // transition at left side -> r = m - 2
8 / 2 = 4
1, 1, 2, 3, 3, 4, 4 (m = 3, m == m + 1) // transition at left side -> r = m - 1
6 / 2 = 3
1, 1, 2, 2, 3, 3, 4, 5, 5 (m = 3, m == m + 1) // transition at right side -> l = m + 2
4, 5, 5
odd (m == m + 1) // transition at left side -> r = m - 1
1, 1, 2 
odd (m == m - 1) // transition at right side -> l = m + 1
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1;
        while(r > l) {
            bool odd = (r - l) / 2 % 2;
            int m = l + (r - l) / 2;
            if (nums[m] == nums[m - 1]) {
                if (odd) l = m + 1;
                else r = m - 2;
            }
            else if (nums[m] == nums[m + 1]) {
                if (odd) r = m - 1;
                else l = m + 2;
            }
            else return nums[m];
        }
        return nums[l];
        
        
    }
};