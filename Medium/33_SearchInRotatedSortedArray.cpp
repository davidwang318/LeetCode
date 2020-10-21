class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) return mid;
            if (mid == left) break;
            // left in order
            if (nums[mid] > nums[left]){
                if (target < nums[mid] && target >= nums[left]) right = mid -1;
                else left = mid + 1;
            }
            // right in order
            else{
                if(target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }   
        }
        return nums[right] == target? right : -1;
    }
};
