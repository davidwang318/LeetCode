class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minNum = nums[0], maxNum = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            int tmpMin = minNum, tmpMax = maxNum;
            maxNum = max(max(tmpMin * nums[i], tmpMax * nums[i]), nums[i]);
            minNum = min(min(tmpMin * nums[i], tmpMax * nums[i]), nums[i]);
            res = max(maxNum, res);
        }
        return res;
    }
};
