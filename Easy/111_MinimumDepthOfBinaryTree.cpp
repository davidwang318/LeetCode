// First Attemp. Having issue on Leaf Node so I need two conditinos.
// Time: 42.58%, Memory: 100.00%
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root -> left) return 1 + minDepth(root -> right);
        if(!root -> right) return 1 + minDepth(root -> left);
        return 1 + min(minDepth(root -> left), minDepth(root -> right));        
    }
};
