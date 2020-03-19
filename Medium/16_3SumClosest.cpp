// First Attempt. Very slow...
// Time: 7.98%, Memory: 100.00%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size(), closeSum = INT_MAX, res = 0;
        if(len < 3) return 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len-2; i++){            
            for (int j = i+1; j < len-1; j++){                
                int k = j+1, tmpSum = nums[i] + nums[j];
                while(k < len-1 && abs(tmpSum+nums[k]-target) >= abs(tmpSum+nums[k+1]-target)) k++;
                if(abs(tmpSum+nums[k]-target) < closeSum) {
                    closeSum = abs(tmpSum+nums[k]-target);
                    res = tmpSum + nums[k];
                }
            }   
        }
        return res;
    }
};

// Saw the discussion and implemented by myself.
// Time: 81.15%, Memory: 100.00%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size(), diff = INT_MAX, res = 0;
        if(len < 3) return 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len-2; i++){
            int l = i+1, r = len-1;
            while(l < r){
                int tmpSum = nums[i] + nums[l] + nums[r];
                if (abs(tmpSum - target) < diff){
                    diff = abs(tmpSum - target);
                    res = tmpSum;
                }   
                if (tmpSum > target) r--;
                else l++;
            }
        }
        
        return res;
    }
};
