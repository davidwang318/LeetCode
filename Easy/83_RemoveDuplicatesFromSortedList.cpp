class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* pre = head, * cur = head -> next;
        while (cur) {
            while(cur && pre -> val == cur -> val)
                cur = cur -> next;
            pre -> next = cur;
            pre = cur;
        }
        return head;
        
    }
};
