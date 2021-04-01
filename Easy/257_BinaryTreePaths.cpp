class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        string curS = std::to_string(root -> val) + "->";
        auto lhs = binaryTreePaths(root -> left);
        auto rhs = binaryTreePaths(root -> right);
        for (auto& s : lhs) res.push_back(curS + s);
        for (auto& s : rhs) res.push_back(curS + s);
        if (res.empty()) res.push_back(std::to_string(root -> val));
        return res;
    }
};