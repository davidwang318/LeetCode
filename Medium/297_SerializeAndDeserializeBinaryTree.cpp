class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeInOrder(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeInOrder(in);
    }
    
private:
    void serializeInOrder(TreeNode* root, ostringstream& out){
        if(!root){
            out << '#' << ' '; return;
        }
        out << root -> val << ' ';
        serializeInOrder(root -> left, out);
        serializeInOrder(root -> right, out);
        return;
    }
    
    TreeNode* deserializeInOrder(istringstream& in){
        string str;
        in >> str;
        if (str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root -> left = deserializeInOrder(in);
        root -> right = deserializeInOrder(in);
        return root;
    }
    
};
