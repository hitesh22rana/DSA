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
    void dfs(TreeNode* root, int targetSum, long long int sum, int &totalPaths) {
        if(root == NULL) return;
        
        sum += root->val;
        
        if(targetSum == sum) {
            totalPaths++;
        }
        
        dfs(root->left, targetSum, sum, totalPaths);
        dfs(root->right, targetSum, sum, totalPaths);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int totalPaths = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                dfs(node, targetSum, 0, totalPaths);
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return totalPaths;        
    }
};