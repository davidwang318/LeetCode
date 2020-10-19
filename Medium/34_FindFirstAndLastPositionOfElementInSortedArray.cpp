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
