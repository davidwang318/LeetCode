// My solution. Not good.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int rIdx = nums.size()-1, cnt = 1, cur = nums[0];
        for (int lIdx = 1; lIdx <= rIdx; lIdx++){
            if (nums[lIdx] == cur) cnt++;
            else {
                cnt = 1;
                cur = nums[lIdx];
            }
            if (cnt > 2) {
                swap(nums[lIdx], nums[rIdx--]);
                sort(nums.begin() + lIdx, nums.begin() + rIdx + 1);
                cnt--;
                lIdx--;
            }
        }
        return rIdx + 1;
    }
};
// Better version
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0, fast = 1, len = nums.size(), cnt = 1;
        while (fast < len) {
            cnt = nums[slow] == nums[fast]? cnt + 1 : 1;
            if (cnt <= 2)
                nums[++slow] = nums[fast++];
            else
                fast ++;
        }
        return slow + 1; // slow is index but we want length
    }
};
