// Delicate but slow. O(nlogn)
// Time: 20.34%, Memory: 73.33%
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[len-1]*nums[0]*nums[1], nums[len-1]*nums[len-2]*nums[len-3]);        
    }
};

// Fast but brutal. O(n)
// Time: 94.08%, Memory: 100.00%
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (const auto num : nums){
            if(num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num > max2){
                max3 = max2;
                max2 = num;
            }
            else if(num > max3) max3 = num;
            
            if(num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if(num < min2) min2 = num;
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};
