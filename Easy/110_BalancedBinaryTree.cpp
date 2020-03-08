// First Attempt. Spend some time on the structure of the code.
// Time: 83.74%, Memory: 96.91%
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(subLength(root->left) - subLength(root->right)) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);        
    }
    
private:
    int subLength(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(subLength(root->left), subLength(root->right));
    }
};

// Can also use -1 to indicate false.
// Time: 83.74%, Memory: 100.00%
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = subLength(root -> left);
        int right = subLength(root -> right);
        if(left == -1 || right == -1 || abs(left - right) > 1) return false;
        return true;        
    }
    
private:
    int subLength(TreeNode* root) {
        if(!root) return 0;
        int left = subLength(root -> left);
        int right = subLength(root -> right);
        if(left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};
