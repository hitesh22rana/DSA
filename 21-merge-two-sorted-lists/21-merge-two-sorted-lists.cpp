/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                tail->next = new ListNode(l1->val);
                tail = tail->next;
                l1 = l1->next;
            } else {
                tail->next = new ListNode(l2->val);
                tail = tail->next;
                l2 = l2->next;
            }
        }
        
        while(l1 != NULL) {
            tail->next = new ListNode(l1->val);
            tail = tail->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            tail->next = new ListNode(l2->val);
            tail = tail->next;
            l2 = l2->next;
        }
        
        return head->next;
    }
};