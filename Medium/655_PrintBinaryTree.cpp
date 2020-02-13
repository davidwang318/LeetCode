// Great use using private function
// Time: 100.00%, Space: 100.00%
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
    vector<vector<string>> printTree(TreeNode* root) {
        int row = getHeight(root), col = (1 << row) - 1;
        vector<vector<string>> res(row, vector<string>(col, ""));
        healper(root, res, 0, 0, col-1);
        return res;
    }
private:
    int getHeight(TreeNode* root){
        if (!root) return 0;
        return max(getHeight(root -> left), getHeight(root -> right)) + 1;
    }
    
    void healper(TreeNode* root, vector<vector<string>>& res, int level,int left, int right){
        if (!root) return;
        int mid = (right-left) / 2 + left;
        res[level][mid] = std::to_string(root -> val);
        healper(root -> left, res, level+1, left, mid-1);
        healper(root -> right, res, level+1, mid+1, right);
        return;
    }
    
};
