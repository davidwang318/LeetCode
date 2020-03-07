// First Attemp.
// Time: 79.68%, Memory: 24.32%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return healper(nums, 0, nums.size());
        
    }
private:
    TreeNode* healper(vector<int>& nums, int left, int right){
        if(left >= right) return NULL;
        int mid = (right-left)/2 + left;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = healper(nums, left, mid);
        root -> right = healper(nums, mid+1, right);
        return root;
    }
};
