class Solution {
public:
    int rob(TreeNode* root) {
        auto res = helper(root);
        return max(res.first, res.second);
    }
    pair<int, int> helper(TreeNode* root){
        if(!root) return {0, 0};
        auto lp = helper(root -> left), rp = helper(root -> right);
        return {(root -> val) + lp.second + rp.second, max(lp.first, lp.second) + max(rp.first, rp.second)};
    }
    
};
