// My solution, still too long for such an easy question
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head -> next) return head;
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* h = dummy, * pre = dummy, * cur = head;
        while(cur) {
            if (cur -> val < x) {
                if (h == pre) {
                    pre = pre -> next;
                    cur = cur -> next;
                }
                else {
                    pre -> next = cur -> next;
                    cur -> next = h -> next;
                    h -> next = cur;
                    cur = pre -> next;
                }
                h = h -> next;
            }
            else {
                pre = pre -> next;
                cur = cur -> next;
            }
        }
        return dummy -> next;        
    }
};
