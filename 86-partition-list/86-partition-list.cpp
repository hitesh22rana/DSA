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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode* head1 = new ListNode();
        ListNode* tail1 = head1;
        
        ListNode* head2 = new ListNode();
        ListNode* tail2 = head2;
        
        while(head != NULL) {
            
            if(head->val < x) {
                tail1->next = new ListNode(head->val);
                tail1 = tail1->next;
            } else {
                tail2->next = new ListNode(head->val);
                tail2 = tail2->next;
            }
            
            head = head->next;
        }
        
        tail1->next = head2->next;
        
        return head1->next;
    }
};