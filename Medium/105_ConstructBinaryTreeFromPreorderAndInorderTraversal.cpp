// Very difficult for me.
// Spend a lot of time debugging
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        int preStart = 0;
        return buildTree(preorder, inorder, m, preStart, 0, inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& m, int& preIdx, int lIdx, int rIdx){
        if (rIdx < lIdx || preIdx >= preorder.size()) return NULL;
        auto idx = preIdx++;
        TreeNode* root = new TreeNode(preorder[idx]);
        if (lIdx == rIdx) return root;
        root -> left = buildTree(preorder, inorder, m, preIdx, lIdx, m[preorder[idx]]-1);
        root -> right = buildTree(preorder, inorder, m, preIdx, m[preorder[idx]]+1, rIdx);
        return root;
    }
             
};
