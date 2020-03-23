// First Attemp. Not so hard.
// Time: 71.64%, Memory: 100.00%
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* nxt = head -> next;
        head -> next = swapPairs(nxt -> next);
        nxt -> next = head;
        return nxt;
    }
};
