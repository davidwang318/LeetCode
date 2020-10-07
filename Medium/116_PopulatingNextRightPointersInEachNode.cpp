// First Attempt. Not a hard question.
// Time: 79.86%, Memory: 100.00%
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
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
// 10.07.2020 
// Another answer
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> s{{root}};
        while(!s.empty()){
            int len = s.size();
            for(int i = 0; i < len; i++){
                auto head = s.front(); s.pop();
                if(head -> left) s.push(head -> left);
                if(head -> right) s.push(head -> right);
                if (i != len-1) head -> next = s.front();
            }
        }
        return root;
    }
};
