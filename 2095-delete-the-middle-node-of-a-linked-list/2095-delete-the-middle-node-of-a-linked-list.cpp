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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;
        
        ListNode* newHead = head;
        
        ListNode* fastptr = head;
        ListNode* slowptr = head;
                
        while(fastptr != nullptr && fastptr->next != nullptr) {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }
        
        if(!slowptr->next) {
            newHead->next = nullptr;
        } else {
            ListNode* next = slowptr->next;
            *slowptr = *next;
            delete(next);
        }
                
        return newHead;
        
    }
};