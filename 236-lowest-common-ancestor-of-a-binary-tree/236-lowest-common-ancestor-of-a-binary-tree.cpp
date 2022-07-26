/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        
        bool left = dfs(root->left,p,q);
        bool right = dfs(root->right,p,q);
        bool mid = (root == p || root == q);
        
        if((mid && left) || (mid && right) || (left && right)) {
            ans = root;
        }
        
        return mid || left || right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};