// First time solving hard question on my own
// But this should be Medium difficulty
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0;
        int res = 0;
        int lIdx = 0, rIdx = len-1;
        int lHeight = height[lIdx], rHeight = height[rIdx];
        while (lIdx <= rIdx) {
            // move lIdx
            if (lHeight <= rHeight) {
                if (height[lIdx] <= lHeight)
                    res += lHeight - height[lIdx++];
                else
                    lHeight = height[lIdx++];
            }
            // move rIdx
            else {
                if (height[rIdx] <= rHeight)
                    res += rHeight - height[rIdx--];
                else
                    rHeight = height[rIdx--];
            }
        }
        return res;
    }
};
