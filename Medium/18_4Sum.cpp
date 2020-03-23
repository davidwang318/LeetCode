// First Attempt. Using set
// Time: 44.53%, Memory: 6.9MB
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 4) return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < len-3; i++){
            for(int j = i+1; j < len-2; j++){
                int target2 = target - nums[i] - nums[j];
                int l = j+1, r = len-1;
                while(l < r){
                    int lrSum = nums[l] + nums[r];
                    if(lrSum == target2) {
                        s.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;
                    }
                    else if(lrSum < target2) l++;
                    else r--;
                }
            }
        }
        return vector<vector<int>> (s.begin(), s.end());
        
    }
};

// Time: 63.52%, Memory: 6.7MB
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < len-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int target2 = target - nums[i] - nums[j];
                int l = j+1, r = len-1;
                while(l < r){
                    int lrSum = nums[l] + nums[r];
                    if(lrSum == target2) {
                        res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                    else if(lrSum < target2) l++;
                    else r--;
                }
            }
        }
        return res;
        
    }
};
