// 10.07.2020
// Pracice day: 5
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrderVec;
        inOrder(root, k, inOrderVec);
        return inOrderVec.back();     
    }
    
    void inOrder(TreeNode* root, int k, vector<int>& vec){
        if(!root) return;
        inOrder(root -> left, k, vec);
        if(vec.size() == k) return;
        vec.push_back(root -> val);
        inOrder(root -> right, k, vec);
        return;
    }
    
};
