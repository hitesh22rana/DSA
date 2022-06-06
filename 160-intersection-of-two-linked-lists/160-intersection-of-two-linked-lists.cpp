/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* getnewNode(ListNode *head , int len) {
        while(len) {
            head = head->next;
            len--;
        }
        return head;
    }
    
    int getLength(ListNode* node) {
        ListNode* temp = node;
        
        int cnt = 0;
        
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        
        return cnt;
        
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        ListNode* head;
        
        
        if(lengthA > lengthB) {
            headA = getnewNode(headA , lengthA - lengthB);
        }
        
        else {
            headB = getnewNode(headB , lengthB - lengthA);
        }
        
        while(headA != NULL && headB != NULL) {
            if(headA == headB) {
                head = headA;
                return head;
            }
            
            headA = headA->next;
            headB = headB->next;
            
        }
        
        return NULL;   
    }
};