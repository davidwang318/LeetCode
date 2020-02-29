// First Attemp
// Hard for me, need to review!
// Time: 65.65%, Memory: 5.14%
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extraDigit = 0;
        ListNode* res = new ListNode(0);
        ListNode* cur = new ListNode(0);
        cur -> next = res;
        while(l1 || l2){
            cur = cur -> next;
            int digit = 0;
            if(l1){
                digit += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                digit += l2 -> val;
                l2 = l2 -> next;
            }
            cur->val += (digit + extraDigit) % 10;
            extraDigit =(digit + extraDigit) / 10;
            ListNode* nxt = new ListNode(0);
            cur -> next = nxt;
        }
        if(extraDigit) cur -> next -> val = extraDigit;
        else cur -> next = NULL;
        return res;
    }
};

// Better version
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* resptr = res;
        int tmp{0}, dummy{0};
        while(l1 || l2 || dummy>0){
            tmp += dummy;
            if (l1){
                tmp += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2){
                tmp += l2 -> val;
                l2 = l2 -> next;
            }
            res -> next = new ListNode(tmp % 10);
            dummy = tmp / 10;
            res = res -> next;
            tmp = 0;
        }
        return resptr -> next;
    }
};
