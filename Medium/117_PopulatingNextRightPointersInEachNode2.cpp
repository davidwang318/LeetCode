// Recursive
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        if (root -> left) {
            if (root -> right)
                root -> left -> next = root -> right;
            else 
                root -> left -> next = getNextChild(root -> next);
        }
        
        if (root -> right)
            root -> right -> next = getNextChild(root -> next);
        
        connect(root -> right);
        connect(root -> left);
        
        return root;
    }
private:
    Node* getNextChild(Node* root) {
        while(root) {
            if (root -> left) return root -> left;
            if (root -> right) return root -> right;
            root = root -> next;
        }
        return root;
    }
};

// Iterative
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q {{root}};
        while(!q.empty()) {
            int curLen = q.size();
            while (curLen-- > 0) {
                Node* cur = q.front(); q.pop();
                if (curLen == 0) cur -> next = nullptr;
                else cur -> next = q.front();
                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
            }
        }
        return root;        
    }
};
