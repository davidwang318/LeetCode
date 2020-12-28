// Constant space method
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* head = root;
        while(head -> left) {
            Node* cur = head;
            while (cur) {
                cur -> left -> next = cur -> right;
                if (cur -> next) cur -> right -> next = cur -> next -> left;
                cur = cur -> next;
            }
            head = head -> left;
        }
        return root;
    }
};
// Queue
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q{{root}};
        while (!q.empty()) {
            int levelLen = q.size();
            for (int i = 0; i < levelLen; i++){
                Node* cur = q.front(); q.pop();
                if(i == levelLen - 1) cur -> next == NULL;
                else cur -> next = q.front();
                if(cur -> left) q.push(cur -> left);
                if(cur -> right) q.push(cur -> right);
            }
        }
        return root;        
    }
};
// Recursive
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root -> left) {
            root -> left -> next = root -> right;
            if(root -> next) 
                root -> right -> next = root -> next -> left;
        }
        connect(root -> left);
        connect(root -> right);
        return root;
    }
};
