class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* pre = dummy, * cur = head;
        // Travel to the head of the reversed list
        for (int i = 1; i < m; i++) {
            pre = pre -> next;
            cur = cur -> next;
        }
        // Reverse one by one for (n - m) elements
        for (int i = 1; i <= n - m; i++) {
            auto tmpNode = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = tmpNode;
        }
        return dummy -> next;       
        
    }
};
