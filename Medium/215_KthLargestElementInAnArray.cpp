// Hard for me
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1, pos = -1;
        while(pos == -1 || pos != k-1){
            pos = partition(nums, left, right);
            if (pos > k - 1) right = pos - 1;
            if (pos < k - 1) left = pos + 1;
        }
        return nums[pos];
    }
private:
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[l], left = l + 1, right = r;
        while(left <= right){
            if (nums[left] < pivot && nums[right] > pivot) {
                swap(nums[left++], nums[right--]);
            }
            if (nums[left] >= pivot) left++;
            if (nums[right] <= pivot) right--;
        }
        swap(nums[right], nums[l]);
        return right;
    }
};
