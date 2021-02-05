class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lIdx = 0, rIdx = numbers.size() - 1;
        while(lIdx != rIdx) {
            int total = numbers[lIdx] + numbers[rIdx];
            if (total == target) return {lIdx+1, rIdx+1};
            else if (total > target) rIdx--;
            else lIdx++;
        }
        return {};
    }
};