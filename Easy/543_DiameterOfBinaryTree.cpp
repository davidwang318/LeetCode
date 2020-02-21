// Not a good way I think. First Attempt.
// Turns out it's a good way.
// Time: 93.53%, Space: 92.59%
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int tmp = maxPath(root, res);
        return res;
        
    }
    
    int maxPath(TreeNode* root, int& maxLen){
        if(!root) return 0;
        int ml = maxPath(root -> left, maxLen), mr = maxPath(root -> right, maxLen);
        maxLen = max(maxLen, ml+mr);
        return max(ml, mr) + 1;  
    } 
};
