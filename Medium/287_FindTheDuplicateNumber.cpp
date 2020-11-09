// My solution: O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1 -> nums[1]
        while(nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};

// Pointer solution: O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) break;
        }
        fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast) break;
        }
        return slow;
        
    }
};
