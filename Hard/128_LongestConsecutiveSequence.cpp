// O(Nlgn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        int cnt = 1, res = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < len; i++){
            int diff = nums[i] - nums[i-1];
            if(diff == 0) continue;
            else if (diff == 1) res = max(res, ++cnt);
            else cnt = 1;
        }
        return res;
        
    }
};

// O(N) solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int num : nums){
            if(!s.count(num)) continue;
            s.erase(num);
            int down = num - 1, up = num + 1;
            while(s.count(down)) s.erase(down--);
            while(s.count(up)) s.erase(up++);
            res = max(res, up - down - 1);
        }
        return res;        
    }
};
