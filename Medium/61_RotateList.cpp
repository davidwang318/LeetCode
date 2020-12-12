// Not hard
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = listSize(head);
        if (len < 2 || k % len == 0) return head;
        int move = len - (k % len);
        ListNode *pre = nullptr, *cur = head;
        while(move-- > 0) {
            pre = cur;
            cur = cur -> next;
        }
        pre -> next = nullptr;
        pre = cur;
        while(cur -> next){
            cur = cur -> next;
        }
        cur -> next = head;
        return pre;
    }
private:
    int listSize(ListNode* head){
        ListNode* h = head;
        int cnt = 0;
        while (h) {
            cnt ++;
            h = h -> next;
        }
        return cnt;
    }
};
