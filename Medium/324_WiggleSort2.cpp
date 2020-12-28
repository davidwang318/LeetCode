// Easy solution
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp {nums};
        sort(tmp.begin(), tmp.end());
        int r = tmp.size() - 1, l = r / 2, cnt = 1;
        for (auto& num : nums)
            num = (cnt++ % 2)? tmp[l--] : tmp[r--];
        return;        
    }
};
