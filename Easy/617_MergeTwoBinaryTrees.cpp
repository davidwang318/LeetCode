// First Attemp
// Time: 42.30%, Memory: 5.55%
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return healper(t1, t2);
    }
    
    TreeNode* healper(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return NULL;
        TreeNode* cur = new TreeNode(0);
        TreeNode* t1l = t1, * t1r = t1, * t2l = t2, * t2r = t2;
        if(t1){
            cur -> val += t1 -> val;
            t1l = t1 -> left;
            t1r = t1 -> right;
        }
        if(t2){
            cur -> val += t2 -> val;
            t2l = t2 -> left;
            t2r = t2 -> right;
        }
        cur -> left = healper(t1l, t2l);
        cur -> right = healper(t1r, t2r);
        return cur;
    }
};
