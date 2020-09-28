// Don't know how to do this in O(1) Space.
// Found the answer on the internet.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA > lenB){
            int diff = lenA - lenB;
            for (int i = 0; i < diff; i++) headA = headA -> next;
        }
        else{
            int diff = lenB - lenA;
            for (int i = 0; i < diff; i++) headB = headB -> next;
        }
        while(headA || headB){
            if (headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
    
private:
    int getLength(ListNode *head){
        int len = 0;
        while (head){
            head = head -> next;
            len ++;
        }
        return len;
        
    }
};
