// Fastest solution
// Time: 95.94%, Memory: 7.14%
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int maxLength = 10000, cnt = nums.size(), ans = 0;
        vector<int> htable (maxLength*2+1, 0);
        for (auto num : nums) htable[num+maxLength]++;
        for (int i = 0; i < maxLength*2; i++){
            if(!htable[i]) continue;
            while(htable[i]-- != 0){
                if(!(cnt-- % 2)) ans += (i-maxLength);
            }
        }
        return ans;
    }
};

// Easy solution
// Time: 73.12%, Memory: 100.00%
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i += 2) ans += nums[i];
        return ans;
    }
};

// Map solution
// Time: 5.22%, Memory: 7.14%
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        map<int, int> s;
        // Ascending order
        for(const auto num : nums){
            auto it = s.find(num);
            if(it == s.end()) s.insert({num, 1});
            else it -> second ++;
        }
        int cnt = nums.size(), ans = 0;
        for(auto element : s){
            for (int i = element.second; i >0 ; i--){
                if(!(cnt % 2)) ans += element.first;
                cnt --;
            }
        }        
        return ans;
    }
};


