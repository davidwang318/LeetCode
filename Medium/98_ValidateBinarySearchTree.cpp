// Inspired by huahualeetcode. Great usage of nullptr
// Time: 98.53%, Memory: 97.92%
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return healper(root, NULL, NULL);        
    }
    bool healper(TreeNode* root, int* leftMax, int *rightMax){
        if(!root) return true;
        if((leftMax && root -> val <= *leftMax) || 
           (rightMax && root -> val >= *rightMax)) return false;
        return healper(root -> left, leftMax, &root->val) && 
               healper(root -> right, &root->val, rightMax);
    }
};

// Great usage of the inorder traversal.
// Time: 90.29%, Memory: 97.92%
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        pre_ = nullptr;
        return inOrder(root);     
    }
private:
    TreeNode* pre_;
    bool inOrder(TreeNode* root){
        if(!root) return true;
        if(!inOrder(root -> left)) return false;
        if(pre_ && root -> val <= pre_ -> val) return false;
        pre_ = root;
        return inOrder(root -> right);
    }
};
