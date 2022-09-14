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
    void dfs(TreeNode* node, int& sum) {
        if(node == NULL) return;
        
        if(node->val % 2 == 0) {
            if(node->left) {
                if(node->left->left) sum += node->left->left->val;
                if(node->left->right) sum += node->left->right->val;
            }
                    
            if(node->right) {
                if(node->right->left) sum += node->right->left->val;
                if(node->right->right) sum += node->right->right->val;
            }
        }
        
        dfs(node->left,sum);
        dfs(node->right,sum);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        
        int sum = 0;
        
        dfs(root,sum);
        return sum;
    }
};