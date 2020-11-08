class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            res = max((right - left) * h, res);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return res;
    }
};
