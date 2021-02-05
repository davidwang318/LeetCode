// 0ms
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m-1, idx2 = n-1;
        for (int i = nums1.size()-1; i >= 0; i--) {
            if (idx1 >= 0 && idx2 >= 0){
                if (nums1[idx1] >= nums2[idx2])
                    nums1[i] = nums1[idx1--];
                else
                    nums1[i] = nums2[idx2--];
            }
            else
                if (idx2 < 0) return;
                else nums1[i] = nums2[idx2--];
        }
        return;        
    }
};