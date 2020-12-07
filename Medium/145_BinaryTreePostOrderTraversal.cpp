// Recursive
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return res;
    }
    void postOrder(TreeNode* root){
        if(!root) return;
        postOrder(root -> left);
        postOrder(root -> right);
        res.push_back(root -> val);
        return;
    }
    vector<int> res;
// Iterative
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        auto t = root;
        while(!s.empty()){
            root = s.top();
            if((!root -> left && !root -> right) || root -> left == t || root -> right == t){
                s.pop();
                res.push_back(root -> val);
                t = root;
                continue;
            }
            if (root -> right) s.push(root -> right);
            if (root -> left) s.push(root -> left);
        }
        return res;
    }
