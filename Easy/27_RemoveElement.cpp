// First Attempt. Use swap.
// Time: 63.36%, Memory: 100.00%
class Solution {
public:
    int removeElement(vector<int>& nums, int val){ 
        int tarIdx = 0, len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] != val) swap(nums[i], nums[tarIdx++]);
        }
        return tarIdx;        
    }
};

// Second Attemp. Faster way.
// Time: 100.00%, Memory: 100.00%
class Solution {
public:
    int removeElement(vector<int>& nums, int val){ 
        int len = nums.size();
        for(int i = 0; i < len; i++){
            while(nums[i] == val && i < len){
                swap(nums[i], nums[--len]);
            }
        }
        return len;        
    }
};
