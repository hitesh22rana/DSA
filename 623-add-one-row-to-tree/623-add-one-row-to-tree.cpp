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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        TreeNode* newRoot = root;
        int currentDepth = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {    
            
            if(depth - 1 == currentDepth) {
                int n = q.size();
                
                for(int i = 0 ; i<n ; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                                        
                    if(node->left) {
                        TreeNode* newNode = new TreeNode(val);
                        newNode->left = node->left;
                        node->left = newNode;
                    } else {
                        TreeNode* newNode = new TreeNode(val);
                        node->left = newNode;
                    }
                    
                    if(node->right) {
                        TreeNode* newNode = new TreeNode(val);
                        newNode->right = node->right;
                        node->right = newNode;
                    } else {
                        TreeNode* newNode = new TreeNode(val);
                        node->right = newNode;
                    }
                }
                
                break;
            }
            
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
            
            currentDepth++;
        }
        
        return root;
    }
};