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
    bool find(TreeNode* root, int target, TreeNode* curr) {
        if(root == nullptr) return false;
                
        if(root != curr && root->val == target) return true;

        return find(root->left, target, curr) || find(root->right, target, curr);
    }
    
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                bool isPresent = find(root, k - node->val, node);
                
                if(isPresent) return true;
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
            
        }
        
        return false;
    }
};