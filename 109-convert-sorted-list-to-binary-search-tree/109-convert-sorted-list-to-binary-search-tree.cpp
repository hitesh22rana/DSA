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
    TreeNode* sortedArrayToBST(vector<int>& arr, int start, int end) {
        if(start > end) return NULL;
        
        int mid = (start + end) / 2;
        
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = sortedArrayToBST(arr, start, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, end);
    
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        vector<int> values;
        
        while(head != NULL) {
            values.push_back(head->val);
            head = head->next;
        }
        
        return sortedArrayToBST(values, 0, values.size() - 1);        
    }
};