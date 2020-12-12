// Very hard to me
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            // left in order
            if (nums[mid] > nums[right]) {
                if (target < nums[mid] && target >= nums[left])
                    right = traverseLeft(nums, mid) - 1;
                else
                    left = traverseRight(nums, mid) + 1;
            }
            // right in order
            else if (nums[mid] < nums[right]) {
                if (target > nums[mid] && target <= nums[right])
                    left = traverseRight(nums, mid) + 1;
                else
                    right = traverseLeft(nums, mid) - 1;
            }
            else
                right --;
        }
        return false;  
    }
private:
    inline
    int traverseRight(vector<int>& nums, int mid) {
        int len = nums.size() - 1;
        while(mid != len && nums[mid+1] == nums[mid]) mid++;
        return mid;
    }
    inline
    int traverseLeft(vector<int>& nums, int mid) {
        while(mid != 0 && nums[mid-1] == nums[mid]) mid--;
        return mid;
    }
};
