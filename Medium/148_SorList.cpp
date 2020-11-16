class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* slow = head, * fast = head, * preSlow = head;
        while(fast && fast -> next){
            preSlow = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        preSlow -> next = NULL;
        return merge(sortList(head), sortList(slow));
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* tmp = new ListNode(0);
        ListNode* head = tmp;
        while(l1 && l2){
            if(l1 -> val <= l2 -> val){
                head -> next = l1;
                l1 = l1 -> next;
            }
            else{
                head -> next = l2;
                l2 = l2 -> next;
            }
            head = head -> next;
        }
        head -> next = l1? l1 : l2;
        return tmp -> next;
    }
};
