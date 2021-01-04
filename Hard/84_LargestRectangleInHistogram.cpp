// Hard
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int res = 0, i = 0, len = height.size();
        while(i < len) {
            if (s.empty() || height[i] > height[s.top()]) {
                s.push(i++);
            }
            else {
                int curHeight = height[s.top()]; s.pop();
                if (s.empty()) res = max(res, curHeight * i);
                else res = max(res, curHeight * (i - s.top() - 1));
            }
        }
        return res;
    }
};
