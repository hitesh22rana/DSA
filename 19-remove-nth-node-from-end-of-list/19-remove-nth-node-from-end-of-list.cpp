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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1 && head->next == NULL) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        
        while(fast != NULL && n > 0) {
            fast = fast->next;
            n--;
        }
        
        while(fast != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if(slow == head) {
            head = head->next;
        }
        
        else {
            prev->next = slow->next;
        }

        return head;
        
    }
};