// Priority queue
// Time: 35.38%, Memory: 100.00%
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode*& a, ListNode*& b) {return a->val > b->val;};
        priority_queue< ListNode*, vector<ListNode*>, decltype(compare) > pq(compare);
        
        for(auto list : lists) if(list) pq.push(list);
        
        ListNode* dummy = new ListNode(-1), * cur = dummy;
        while(!pq.empty()){
            cur -> next = pq.top(); pq.pop();
            cur = cur -> next;
            if(cur -> next) pq.push(cur -> next);            
        }
        return dummy -> next;  
    }
};

// Merge sort
// Time: 72.90%, Memory: 100.00%
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while(len > 1){
            int mid = (len % 2)? len/2+1 : len/2; // 3 -> 2, 4 -> 2, 5 -> 3
            for(int i = 0; i < len/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i+mid]);
            }
            len = mid;
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1), * cur = dummy;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else{
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next; 
        }
        cur -> next = (l1) ? l1 : l2;
        return dummy -> next;
    }
};
