// Iterative: Easy
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                res.push_back(root -> val);
                s.push(root);
                root = root -> left;
            }
            root = s.top(); s.pop();
            root = root -> right;
        }
        return res;    
    }
};
// Recursive: Easy
    Vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return res;
    }
    void preOrder(TreeNode* root){
        if (!root) return;
        res.push_back(root -> val);
        preOrder(root -> left);
        preOrder(root -> right);
        return;
    }
    vector<int> res;

