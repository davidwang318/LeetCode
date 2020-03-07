// First Attemp. Not a good solution.
// Time: 49.39%, Memory: 9.09%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> res1 = listToVector(head);
        return vectorToBST(res1, 0, res1.size());
    }
    
private:
    vector<int> listToVector(ListNode* head){
        vector<int> res;
        while(head){
            res.push_back(head->val);
            head = head -> next;
        }
        return res;
    }
    
    TreeNode* vectorToBST(vector<int>& nums, int left, int right){
        if(left >= right) return NULL;
        int mid = (right - left)/2 + left;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = vectorToBST(nums, left, mid);
        root -> right = vectorToBST(nums, mid+1, right);
        return root;
    }
};

// Fast slow pointer! Need to review these concepts.
// Time: 72.85%, Memory: 9.09%
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return findMid(head, NULL);
    }
private:
    TreeNode* findMid(ListNode* head, ListNode* tail){
        if(head == tail) return NULL;
        ListNode* fast = head, * slow = head;
        while(fast != tail && fast -> next != tail){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        TreeNode* root = new TreeNode(slow -> val);
        root -> left = findMid(head, slow);
        root -> right = findMid(slow -> next, tail);
        return root;
    }
};
