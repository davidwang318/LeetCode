// Brilliant sorting algorithm!
// Time: 97.75%, Space: 83.33%
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // To know whether this is the repeat element
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i+1) res.push_back(i+1);
        return res;
    }
};


// Smart solution, Use original array to count whether its appear or not, abs!
// Time: 92.54%, Space: 83.33%

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(const auto num : nums){
            int idx = abs(num) - 1;
            nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
        }
        for (int i = 0; i < len; i++){
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

// Intuitive soloution
// Time: 75.35%, Space: 10.00%

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(len, 0), res;
        for(const auto num : nums) count[num-1]++;
        for(int i = 0; i < len; i ++){
            if(count[i] == 0) res.push_back(i+1);
        }
        return res;
    }
};



