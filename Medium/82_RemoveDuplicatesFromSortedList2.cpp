class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* pre = dummy, * cur = head;
        while (pre -> next) {
            while (cur -> next && cur -> val == cur -> next -> val)
                cur = cur -> next;
            if (pre -> next != cur) pre -> next = cur -> next;
            else pre = pre -> next;
            cur = cur -> next;
        }
        return dummy -> next;        
    }
};
