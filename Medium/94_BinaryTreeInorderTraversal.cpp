// Recursive solutionL: Easy
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Left, Root, Right
        vector<int> res;
        inorderTraversal(root, res);
        return res;
        
    }
    void inorderTraversal(TreeNode* root, vector<int> &res){
        if(!root) return;
        inorderTraversal(root -> left, res);
        res.push_back(root -> val);
        inorderTraversal(root -> right, res);
        return;
    }
};
// Iterative solution: Hard
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root -> left;
            }
            root = s.top(); s.pop();
            res.push_back(root -> val);
            root = root -> right;
        }
        return res;

    }
};
