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
class compare {
public:
    bool operator()(ListNode* a , ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare> pq;
        
        int n = lists.size();
        if(n == 0) return NULL;
    
        for(int i = 0 ; i<n ; i++) {
            if(lists[i]) {
                pq.push(lists[i]);
            }        
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            if(node->next) {
                pq.push(node->next);
            }

            if(head == NULL) {
                head = node;
                tail = node;  
            } else {
                tail->next = node;
                tail = node;
            }

        }

        return head;
    }
};