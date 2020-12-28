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

// Correct approach
// Very hard to understand the meaning of target. Why can't I use the index of the array?
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size(); 
        n2 = nums2.size(); 
        int k1 = (n1 + n2 + 1) / 2, k2 = (n1 + n2 + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, k1) + findKth(nums1, 0, nums2, 0, k2)) / 2.0;
    }
private:
    int findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int target){
        if (start1 >= n1) return nums2[start2+target-1];
        if (start2 >= n2) return nums1[start1+target-1];
        if (target == 1) return min(nums1[start1], nums2[start2]);
        if (start1 + target / 2 - 1 >= n1) return findKth(nums1, start1, nums2, start2 + target / 2, target - target / 2);
        if (start2 + target / 2 - 1 >= n2) return findKth(nums1, start1 + target / 2, nums2, start2, target - target / 2);
        if (nums1[start1 + target / 2 - 1] > nums2[start2 + target / 2 - 1])
            return findKth(nums1, start1, nums2, start2 + target / 2, target - target / 2);
        else
            return findKth(nums1, start1 + target / 2, nums2, start2, target - target / 2);
    }
    int n1, n2;
};

// More intuitive to me
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size(); 
        n2 = nums2.size(); 
        int k1 = (n1 + n2 - 1) / 2, k2 = (n1 + n2) / 2;
        return (findKth(nums1, 0, nums2, 0, k1) + findKth(nums1, 0, nums2, 0, k2)) / 2.0;
    }
private:
    int findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int target){
        if (start1 >= n1) return nums2[start2 + target];
        if (start2 >= n2) return nums1[start1 + target];
        if (target == 0) return min(nums1[start1], nums2[start2]);
        int idx = (target - 1) / 2;
        if (start1 + idx >= n1) return findKth(nums1, start1, nums2, start2 + idx + 1, target - idx - 1);
        if (start2 + idx >= n2) return findKth(nums1, start1 + idx + 1, nums2, start2, target - idx - 1);
        if (nums1[start1 + idx] > nums2[start2 + idx])
            return findKth(nums1, start1, nums2, start2 + idx + 1, target - idx - 1);
        else
            return findKth(nums1, start1 + idx + 1, nums2, start2, target - idx - 1);
    }
    int n1, n2;
};
