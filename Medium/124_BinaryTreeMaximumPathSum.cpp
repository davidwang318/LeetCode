// My answer
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return INT_MIN;
        int res = root -> val;
        int dummy = healper(root, res);
        return res;
    }
private:
    int healper(TreeNode* root, int& maxPath){
        if (!root) return 0;
        int left = max(0, healper(root -> left, maxPath));
        int right = max(0, healper(root -> right, maxPath));
        int cur = root -> val;
        maxPath = max(maxPath, cur + left + right);
        cur += left > right? left : right;
        return cur;
    }
};
