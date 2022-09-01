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
    void countNodes(TreeNode* root, int prev, int& count) {
        if(root == NULL) return;
        if(root->val >= prev) count++;
        prev = max(root->val,prev);
        
        countNodes(root->left,prev,count);
        countNodes(root->right,prev,count);
    }
    
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        int prev = INT_MIN;
        countNodes(root,prev,count);
        return count;        
    }
};