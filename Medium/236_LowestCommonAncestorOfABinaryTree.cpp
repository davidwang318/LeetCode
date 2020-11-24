class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool flag = false;
        TreeNode* res = new TreeNode(0);
        if(checkExist(root, p, q, flag, res)) return res;
        return NULL;
        
    }
private:
    bool checkExist(TreeNode* root, TreeNode* p, TreeNode* q, bool& findFlag, TreeNode*& res){
        if(!root) return false;
        if(findFlag) return true;
        bool curFlag = root == p || root == q;
        bool leftFlag = checkExist(root -> left, p, q, findFlag, res);
        bool rightFlag = checkExist(root -> right, p, q, findFlag, res);
        if (curFlag + leftFlag + rightFlag == 2 && !findFlag){
            res = root;
            findFlag = true;
        }
        return curFlag || leftFlag || rightFlag;
    }
};

// Great answer from the discussion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        if(left && left != p && left != q) return left;
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(right && right != p && right != q) return right;
        if(left && right) return root;
        return left? left : right;        
    }
};
