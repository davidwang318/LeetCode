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
    // Recursive answer
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        if(root -> left && !root -> left -> left && !root -> left -> right) sum = root -> left -> val;
        return sum + sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);        
    }
};

class Solution {
    // Iteration answer
public:
    int sumOfLeftLeaves(TreeNode* root) {
        std::queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root){
                if(root -> left && !root -> left -> left && !root -> left -> right) sum += root -> left -> val;
                q.push(root -> left);
                q.push(root -> right);
            }
        }
        return sum;
    }
};
