class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq{nums[0]};
        // Construct the first window
        for(int i = 1; i < k; i ++){
            while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        // Maintain the window
        vector<int> res;
        for(int i = 0; i < nums.size() - k; i ++){
            res.push_back(dq.front());
            if(nums[i] == dq.front()) dq.pop_front();
            while(!dq.empty() && dq.back() < nums[i+k]) dq.pop_back();
            dq.push_back(nums[i+k]);
        }
        // Push the last one
        res.push_back(dq.front());
        return res;
    }
};
