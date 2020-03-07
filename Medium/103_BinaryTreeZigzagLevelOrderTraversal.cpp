// First Attemp. 
// Time: 100.00%, Memory: 100.00%
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        bool zig = true;
        vector<vector<int>> res;
        queue<TreeNode*> q {{root}};
        
        while(!q.empty()){
            int curLen = q.size();
            vector<int> curRes (curLen, 0);
            for(int i = 0; i < curLen; i++){
                TreeNode* cur = q.front(); q.pop();
                if(zig) curRes[i] = cur -> val;
                else curRes[curLen-i-1] = cur -> val;
                
                if(cur -> left) q.push(cur -> left);
                if(cur -> right) q.push(cur -> right);
            }
            res.push_back(curRes);
            zig = !zig;
        }
        
        return res;
        
    }
};

