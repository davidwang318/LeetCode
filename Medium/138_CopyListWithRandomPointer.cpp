// Be ware of left value / right value!
// Time: 98.76%, Memory: 100.00%
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        unordered_map<Node*, Node*> m;
        Node* res = new Node(head->val), * curRes = res, * curHead = head->next;
        m[head] = res;
        
        // Copy *next
        while(curHead){
            curRes -> next = new Node(curHead -> val);
            m[curHead] = curRes -> next;
            curRes = curRes -> next;
            curHead = curHead -> next;
        }
        // Copy *random
        curRes = res; curHead = head;
        while(curHead){
            if(curHead -> random) curRes -> random = m[curHead -> random];
            curHead = curHead -> next;
            curRes = curRes -> next;
        }
        
        return res;        
    }
};

// Space: O(1) solution. Brilliant.
// Time: 98.76%, 100.00%
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* cur = head;
        // Insert a node between each node
        while(cur){
            Node* between = new Node(cur->val);
            between -> next = cur -> next;
            cur -> next = between;
            cur = cur -> next -> next;
        }
        // Assign random pointer
        cur = head;
        while(cur){
            if(cur -> random) cur -> next -> random = cur -> random -> next;
            cur = cur -> next -> next;
        }
        // Break the link
        Node* res = head -> next;
        cur = head;
        while(cur){
            Node* tmp = cur -> next;
            cur -> next = cur -> next -> next;
            if(tmp -> next) tmp -> next = tmp -> next -> next;
            cur = cur -> next;
        }
        return res;        
        
    }
};
