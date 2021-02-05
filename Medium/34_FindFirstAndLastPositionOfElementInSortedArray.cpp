// Better template 2/1/2020
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(nums, target),
                upper_bound(nums, target)};
    }
private:
    // First index of i such that A[i] >= target
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        if (l == nums.size() || nums[l] != target) return -1;
        return l;
    }
    // First index of i such that A[i] > target
    int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) r = m; // why don't set it as m - 1 ?
            else l = m + 1; // Because l needs to be m + 1 to prevent infinite loop
        }
        if (l == 0 || nums[l-1] != target) return -1;
        return l - 1;
    }
};

// Hard
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        searchLeftRange(nums, res, target, 0, nums.size());
        if (res[0] == -1) return res;
        else searchRightRange(nums, res, target, 0, nums.size());
        return res;
    }
private:
    void searchLeftRange(vector<int>& nums, vector<int>& res, int target, int left, int right){
        if (left == right){
            if (right != nums.size() && nums[right] == target) res[0] = right;
            return;
        }
        int mid = (right - left) / 2 + left;
        if (nums[mid] < target) searchLeftRange(nums, res, target, mid + 1, right);
        else searchLeftRange(nums, res, target, left, mid);
        return;        
    }
    void searchRightRange(vector<int>& nums, vector<int>& res, int target, int left, int right){
        if (left == right){
            res[1] = right - 1;
            return;
        }
        int mid = (right - left) / 2 + left;
        if (nums[mid] <= target) searchRightRange(nums, res, target, mid+1, right);
        else searchRightRange(nums, res, target, left, mid);
        return;        
    }
};
