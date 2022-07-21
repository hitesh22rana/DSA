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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        for(int i = 0 ; curr != NULL && i<left-1 ; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* last = prev;
        ListNode* newEnd = curr;
        
        ListNode* next = curr->next;
        
        for(int i = 0 ; curr != NULL && i <= right-left ; i++) {
            curr->next = prev;
            prev = curr;
            curr = next;
            
            if(next != NULL) {
                next = next->next;
            }
        }
        
        if(last != NULL) {
            last->next = prev;
        }
        
        else {
            head = prev;
        }
     
        newEnd->next = curr;
        
        return head;
    }
};