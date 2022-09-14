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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tail = head;
        ListNode* ans = new ListNode();
        ListNode* ansTail = ans;
        
        while(tail != NULL) {
            if(tail->val == 0) {
                int sum = 0;
                ListNode* newTail = tail->next;
                
                while(newTail != NULL) {
                    if(newTail->val == 0) {
                        break;
                    }    
                    sum += newTail->val;
                    newTail = newTail->next;
                }
                
                if(sum > 0) {
                    ansTail->next = new ListNode(sum);
                    ansTail = ansTail->next;                    
                }
            }
            
            tail = tail->next;
        }
        
        return ans->next;
    }
};