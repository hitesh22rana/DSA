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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getValue(ListNode* head, int mid) {
        while(mid--) {
            if(head == NULL) return -1;
            
            head = head->next;
        }
        
        return head->val;
    }
    
    TreeNode* sortedArrayToBST(ListNode* head, int start, int end) {
        if(start > end) return NULL;
        
        int mid = (start + end) / 2;
        
        int valAtMid = getValue(head, mid);
        
        TreeNode* root = new TreeNode(valAtMid);
        
        root->left = sortedArrayToBST(head, start, mid - 1);
        root->right = sortedArrayToBST(head, mid + 1, end);
    
        return root;
    }
    
    int lengthOfList(ListNode* head) {
        int size = 0;
        
        while(head != NULL) {
            size++;
            head = head->next;
        }
        
        return size++;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        int size = lengthOfList(head);

        return sortedArrayToBST(head, 0, size - 1);        
    }
};