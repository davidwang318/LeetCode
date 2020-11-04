class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> forward(len, 1), backward(len, 1);
        for(int i = 1; i < len; i ++){
            int j = nums.size() - 1 - i;
            forward[i] = nums[i-1] * forward[i-1];
            backward[j] = nums[j+1] * backward[j+1];
        }
        for(int i = 0; i < len; i ++){
            forward[i] = forward[i] * backward[i];
        }
        return forward;        
    }
};
