// Better solution
/*
Can't determine which one is totally the same:
112111111
111111211
so we can't do anything when there is the same at both end
but if we know it's not the same at one end
2111111
1111112
we can determine the order
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return true;
            if (nums[m] == nums[l]) l++;
            else if (nums[m] == nums[r]) r--;
            // right in order
            else if (nums[m] < nums[r]) {
                if (target > nums[m] && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
            // left in order
            else {
                if (target < nums[m] && target >= nums[l]) r = m - 1;
                else l = m + 1;
            }
        }
        return false;
    }
};

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
