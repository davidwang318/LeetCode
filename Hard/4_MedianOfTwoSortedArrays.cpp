// First Attemp with 4 Runtime Error...
// Still, need to check 4 times of the boundary condition.
// Time: 99.82%, Memory: 100.00%
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), len = len1 + len2;
        int mid = len / 2;
        vector<int> merge(mid+1, 0);
        if (len1 == 0 || len2 == 0){
            merge = (len1 == 0)? nums2 : nums1;
        }
        else{
            int i = 0, j = 0, idx = 0;
            while(i+j != mid+1){
                if(j == len2 || (i != len1 && nums1[i] < nums2[j])) merge[idx++] = nums1[i++];
                else merge[idx++] = nums2[j++];
            }
        }
        
        if(len % 2 == 1) return merge[mid];
        return (merge[mid-1] + merge[mid]) / 2.0;
    }
};
